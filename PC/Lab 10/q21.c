#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <assert.h>

// Creates an array of random floats. Each number has a value from 0 - 1
float *create_rand_nums(const int num_elements)
{
    float *rand_nums = (float *)malloc(sizeof(float) * num_elements);
    assert(rand_nums != NULL);
    for (int i = 0; i < num_elements; i++)
    {
        rand_nums[i] = (rand() / (float)RAND_MAX);
    }
    return rand_nums;
}

// Distance**2 between d-vectors pointed to by v1, v2.
float distance2(const float *v1, const float *v2, const int d)
{
    float dist = 0.0;
    for (int i = 0; i < d; i++)
    {
        float diff = v1[i] - v2[i];
        dist += diff * diff;
    }
    return dist;
}

// Assign a site to the correct cluster by computing its distances to each cluster centroid.
int assign_site(const float *site, float *centroids, const int k, const int d)
{
    int best_cluster = 0;
    float best_dist = distance2(site, centroids, d);
    float *centroid = centroids + d;
    for (int c = 1; c < k; c++, centroid += d)
    {
        float dist = distance2(site, centroid, d);
        if (dist < best_dist)
        {
            best_cluster = c;
            best_dist = dist;
        }
    }
    return best_cluster;
}

void add_site(const float *site, float *sum, const int d)
{
    for (int i = 0; i < d; i++)
        sum[i] += site[i];
}

void print_centroids(float *centroids, const int k, const int d)
{
    float *p = centroids;
    printf("Centroids:\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < d; j++, p++)
        {
            printf("%f ", *p);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int sites_per_proc, d, rank, nprocs, k;
    sites_per_proc = 2000;
    d = 2;
    if (argc != 2)
    {
        fprintf(stderr,"Incorrect args\n");
        exit(1);
    }
    k = atoi(argv[1]);

    srand(31359);
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    float *sites;
    assert(sites = malloc(sites_per_proc * d * sizeof(float)));
    float *sums;
    assert(sums = malloc(k * d * sizeof(float)));
    // The number of sites assigned to each cluster by this process. k integers.
    int *counts;
    assert(counts = malloc(k * sizeof(int)));
    // The current centroids against which sites are being compared.
    float *centroids;
    assert(centroids = malloc(k * d * sizeof(float)));
    // The cluster assignments for each site.
    int *labels;
    assert(labels = malloc(sites_per_proc * sizeof(int)));

    // All the sites for all the processes.
    float *all_sites = NULL;
    // Sum of sites assigned to each cluster by all processes.
    float *grand_sums = NULL;
    // Number of sites assigned to each cluster by all processes.
    int *grand_counts = NULL;
    int *all_labels;
    if (rank == 0)
    {
       printf("Starting random initialization..\n");
        all_sites = create_rand_nums(d * sites_per_proc * nprocs);
        for (int i = 0; i < k * d; i++)
        {
            centroids[i] = all_sites[i];
        }
        assert(grand_sums = malloc(k * d * sizeof(float)));
        assert(grand_counts = malloc(k * sizeof(int)));
        assert(all_labels = malloc(nprocs * sites_per_proc * sizeof(int)));
        printf("Nodes initialized \n");
    }
    double start_time = MPI_Wtime();
    // Root sends each process its share of sites.
    MPI_Scatter(all_sites, d * sites_per_proc, MPI_FLOAT, sites, d * sites_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);

    float norm = 1.0; 
    // Will tell if centroids have changed

    while (norm > 0.00001)
    {   // Broadcast the current cluster centroids to all processes.
        MPI_Bcast(centroids, k * d, MPI_FLOAT, 0, MPI_COMM_WORLD);

        // Each process reinitializes its cluster accumulators.
        for (int i = 0; i < k * d; i++)
            sums[i] = 0.0;
        for (int i = 0; i < k; i++)
            counts[i] = 0;

        // Find the closest centroid to each site and assign to cluster.
        float *site = sites;
        for (int i = 0; i < sites_per_proc; i++, site += d)
        {
            int cluster = assign_site(site, centroids, k, d);
            // Record the assignment of the site to the cluster.
            counts[cluster]++;
            add_site(site, &sums[cluster * d], d);
        }

        // Gather and sum at root all cluster sums for individual processes.
        MPI_Reduce(sums, grand_sums, k * d, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Reduce(counts, grand_counts, k, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        if (rank == 0)
        {
            // Root process computes new centroids by dividing sums per cluster
            // by count per cluster.
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    int dij = d * i + j;
                    grand_sums[dij] /= grand_counts[i];
                }
            }
            norm = distance2(grand_sums, centroids, d * k);
            printf("norm: %f\n", norm);
            // Copy new centroids from grand_sums into centroids.
            for (int i = 0; i < k * d; i++)
            {
                centroids[i] = grand_sums[i];
            }
            print_centroids(centroids, k, d);
        }
        // Broadcast the norm. to all processes
        MPI_Bcast(&norm, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    }

    // Centroids are fixed, so compute a final label for each site.
    float *site = sites;
    for (int i = 0; i < sites_per_proc; i++, site += d)
    {
        labels[i] = assign_site(site, centroids, k, d);
    }

    // Gather all labels into root process.
    MPI_Gather(labels, sites_per_proc, MPI_INT, all_labels, sites_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
    // Root can print out all sites and labels.
    MPI_Barrier(MPI_COMM_WORLD);
    double end_time = MPI_Wtime() - start_time;
    if (rank == 0)
    {
        float *site = all_sites;
        printf("Plotting nodes...\n");
        printf("Time: %fs\n",end_time);
    }
    MPI_Finalize();
}