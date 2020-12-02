#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <assert.h>

const int  N = 1e5;

/*
N: No. of array elements
temp_arr: Temperature array in server
humid_arr: Humidity array in server
start_val: First array index for a process
end_val: Last array index for a process
Every processor finds local sum for array elemnts with index between start_val & end_val
local_sum: Stores local sum calculated by each process
global_sum: Obtained through reduction -> Stores sum of all array elements
seq_sum: Sum of all elements obtained sequentially
*/

int main(int argc, char *argv[])
{
    int rank, size, n, temp_arr[N], humid_arr[N], start_val, end_val;
    int temp_seq_sum, temp_local_sum, temp_global_sum, humid_seq_sum, humid_local_sum, humid_global_sum;
    double start, fin;
    temp_seq_sum = temp_local_sum = temp_global_sum = humid_seq_sum = humid_local_sum = humid_global_sum = 0;
    
    // Initializing array elements
    srand(rank+1);
    for (int i = 0; i < N; i++)
    {
        temp_arr[i] = i;
        humid_arr[i] = i%10;
    }
    
    // Sequential execution
    clock_t begin = clock();
    for (int i = 0; i < N; i++)
    {
        temp_seq_sum = temp_seq_sum + temp_arr[i];
        humid_seq_sum = humid_seq_sum + humid_arr[i];
    }
    clock_t end = clock();
    
    // MPI initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Starting clock for recording time
    start = MPI_Wtime();
    start_val = N * rank / size + 1;
    end_val = N * (rank + 1) / size;
    n = N / size;
    
    // Calculation of local sum at processor level
    for (int i = start_val; i <= end_val; i++)
    {   temp_local_sum = temp_local_sum + temp_arr[i];
        humid_local_sum = humid_local_sum + humid_arr[i];
    }
    
    // Reduction to get global sum of array elements
    MPI_Reduce(&temp_local_sum, &temp_global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&humid_local_sum, &humid_global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    // Barrier to synchronize all processes before calculating time
    MPI_Barrier(MPI_COMM_WORLD);
    fin = MPI_Wtime();

    // Display statistics at root
    if (rank == 0)
    {
        printf("Average Temperature\n");
        printf("Using sequential is: %.2f\t Using parallel is: %.2f", temp_seq_sum / (1. * N), temp_global_sum / (1. * N));
        printf("\n---------------------\n");
        printf("Average Humidity\n");
        printf("Using sequential is: %.2f\t Using parallel is: %.2f", humid_seq_sum / (1. * N), humid_global_sum / (1. * N));
        printf("\n---------------------\n");
        printf("Sequential Execution took: %.4fs\n", (double)(end - begin) / CLOCKS_PER_SEC);
        printf("Parallel Execution with %d processes took: %.4fs\n", size, fin-start);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}