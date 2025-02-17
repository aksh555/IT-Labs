#include <mpi.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char message[20];
    int myrank;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0) /* code for process zero */
    {
        strcpy(message, "Hello world");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 10, MPI_COMM_WORLD);
    }
    else if (myrank == 1) /* code for process one */
    {
        MPI_Recv(message, 20, MPI_CHAR, 0, 10, MPI_COMM_WORLD, &status);
        printf("Received : %s\n", message);
    }
    MPI_Finalize();
    return 0;
}