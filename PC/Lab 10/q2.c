#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
float *create_rand_nums(const int num_elements)
{
    float *rand_nums = (float *)malloc(sizeof(float) * num_elements);
    float a = 999;
    for (int i = 0; i < num_elements; i++)
    {
        rand_nums[i] = ((float)rand() / (float)RAND_MAX) * a;
    }
    return rand_nums;
}
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
int assign_site(const float *site, float *centroids,
                const int k, const int d)
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
    {
        sum[i] += site[i];
    }
}
void print_centroids(float *centroids, const int k, const int d)
{
    FILE *fp;
    char *filename = "cluster_parallel.txt";
    fp = fopen(filename, "w");
    float *p = centroids;
    printf("Centroids:\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < d; j++, p++)
        {
            printf("%f ", *p);
            fprintf(fp, "%f ", *p);
        }
        fprintf(fp, "%d\n", i);
        printf("\n");
    }
}
double kmeans_serial(float *all_sites, int k, int arr_size)
{
    float *centroids;
    centroids = malloc(k * 2 * sizeof(float));
    float *grand_sums = NULL;
    int *grand_counts = NULL;
    int *all_labels;
    for (int i = 0; i < k * 2; i++)
    {
        centroids[i] = all_sites[i];
    }
    grand_sums = malloc(k * 2 * sizeof(float));
    grand_counts = malloc(k * sizeof(int));
    all_labels = malloc(arr_size * sizeof(int));
    double start_time = MPI_Wtime();
    float norm = 1.0;
    while (norm > 0.00001)
    {
        for (int i = 0; i < k * 2; i++)
            grand_sums[i] = 0.0;
        for (int i = 0; i < k; i++)
            grand_counts[i] = 0;
        float *site = all_sites;
        for (int i = 0; i < arr_size; i++, site += 2)
        {
            int cluster = assign_site(site, centroids, k, 2);
            grand_counts[cluster]++;
            add_site(site, &grand_sums[cluster * 2], 2);
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int dij = 2 * i + j;
                grand_sums[dij] /= grand_counts[i];
            }
        }
        norm = distance2(grand_sums, centroids, 2 * k);
        for (int i = 0; i < k * 2; i++)
        {
            centroids[i] = grand_sums[i];
        }
    }
    float *site = all_sites;
    for (int i = 0; i < arr_size; i++, site += 2)
    {
        all_labels[i] = assign_site(site, centroids, k, 2);
    }
    double end_time = MPI_Wtime() - start_time;
    printf("serial %f \n", end_time);
    print_centroids(centroids, k, 2);
    return 0;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr,
                "Usage: kmeans num_sites_per_proc num_means num_dimensions\n");
        exit(1);
    }
    int sites_per_proc = atoi(argv[1]);
    int k = atoi(argv[2]); // number of clusters.
    srand(31359);
    MPI_Init(NULL, NULL);
    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    float *sites;
    sites = malloc(sites_per_proc * 2 * sizeof(float));
    float *sums;
    sums = malloc(k * 2 * sizeof(float));
    int *counts;
    counts = malloc(k * sizeof(int));
    float *centroids;
    centroids = malloc(k * 2 * sizeof(float));
    int *labels;
    labels = malloc(sites_per_proc * sizeof(int));
    float *all_sites = NULL;
    float *grand_sums = NULL;
    int *grand_counts = NULL;
    int *all_labels;
    if (rank == 0)
    {
        all_sites = create_rand_nums(2 * sites_per_proc * nprocs);
        for (int i = 0; i < k * 2; i++)
        {
            centroids[i] = all_sites[i];
        }
        grand_sums = malloc(k * 2 * sizeof(float));
        grand_counts = malloc(k * sizeof(int));
        all_labels = malloc(nprocs * sites_per_proc * sizeof(int));
    }
    MPI_Scatter(all_sites, 2 * sites_per_proc, MPI_FLOAT, sites,
                2 * sites_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();
    float norm = 1.0;
    while (norm > 0.00001)
    {
        MPI_Bcast(centroids, k * 2, MPI_FLOAT, 0, MPI_COMM_WORLD);
        for (int i = 0; i < k * 2; i++)
            sums[i] = 0.0;
        for (int i = 0; i < k; i++)
            counts[i] = 0;
        float *site = sites;
        for (int i = 0; i < sites_per_proc; i++, site += 2)
        {
            int cluster = assign_site(site, centroids, k, 2);
            counts[cluster]++;
            add_site(site, &sums[cluster * 2], 2);
        }
        MPI_Reduce(sums, grand_sums, k * 2, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Reduce(counts, grand_counts, k, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        if (rank == 0)
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    int dij = 2 * i + j;
                    grand_sums[dij] /= grand_counts[i];
                }
            }
            norm = distance2(grand_sums, centroids, 2 * k);
            for (int i = 0; i < k * 2; i++)
            {
                centroids[i] = grand_sums[i];
            }
        }
        MPI_Bcast(&norm, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    }
    float *site = sites;
    for (int i = 0; i < sites_per_proc; i++, site += 2)
    {
        labels[i] = assign_site(site, centroids, k, 2);
    }
    MPI_Gather(labels, sites_per_proc, MPI_INT, all_labels, sites_per_proc, MPI_INT, 0,
               MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    double end_time = MPI_Wtime() - start_time;
    if (rank == 0)
    {
        printf("Parallel %f \n", end_time);
        print_centroids(centroids, k, 2);
    }
    if ((rank == 0) && 1)
    {
        FILE *fp;
        char *filename = "point_parallel.txt";
        fp = fopen(filename, "w");
        float *site = all_sites;
        for (int i = 0; i < nprocs * sites_per_proc; i++, site += 2)
        {
            fprintf(fp, "%f %f %d \n", site[0], site[1], all_labels[i]);
        }
        fclose(fp);
        kmeans_serial(all_sites, k, nprocs * sites_per_proc);
    }
    MPI_Finalize();
}