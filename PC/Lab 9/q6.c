#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <mpi.h>

// No.of elements each processor works on
const long int local_size = 4*1e4;

int main(int argc, char **argv)
{
    int rank, size,local_arr[local_size],local_min[2],global_min[2];
    double start,end;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    srand(rank+1);
    start = MPI_Wtime();
    for (int i = 0; i < local_size; i++)
        local_arr[i] = rand()%100;

    local_min[0] = local_arr[0];
    for (int i = 1; i < local_size; i++)
        if (local_arr[i] < local_min[0])
            local_min[0] = local_arr[i];

    local_min[1] = rank;
    MPI_Reduce(local_min, global_min, 1, MPI_2INT, MPI_MINLOC, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();
    if (rank == 0)
    {
        printf("No. of processes = %d\t Chunk size = %ld\nNo. of elements in array is %ld\nRank %d has lowest value of %d\n", size, local_size, local_size*size, global_min[1], global_min[0]);
        printf("Time taken is %f \n", end-start);
    }
    MPI_Finalize();
    return 0;
}


/*
No. of processes = 1     Chunk size = 1000000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.019354 

No. of processes = 5     Chunk size = 200000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.013439 

No. of processes = 10    Chunk size = 100000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.009126 

No. of processes = 20    Chunk size = 50000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.008890 

No. of processes = 25    Chunk size = 40000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.011216 

No. of processes = 50    Chunk size = 20000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.051067 

No. of processes = 100   Chunk size = 10000
No. of elements in array is 1000000
Rank 0 has lowest value of 0
Time taken is 0.088301 
*/