#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int size, myrank, x[10], i, y[10];
    MPI_Status status;
    MPI_Request request;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0)
    {
        for (i = 0; i < 10; i++)
        {
            x[i] = 1;
            y[i] = 2;
        }
        MPI_Send(x, 10, MPI_INT, 1, 1, MPI_COMM_WORLD); 
        MPI_Send(y, 10, MPI_INT, 1, 2, MPI_COMM_WORLD);
    }
    else if (myrank == 1)
    {
        MPI_Recv(x, 10, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
        for (i = 0; i < 10; i++)
            printf("Received Array x : %d\n", x[i]);
        MPI_Recv(y, 10, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (i = 0; i < 10; i++)
            printf("Received Array y : %d\n", y[i]);
    }
    MPI_Finalize();
    return 0;
}