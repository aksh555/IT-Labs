#include <mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,char **argv){
	int size,rank,i,res,chunk;
	int x[1000000];
	int y[1000000];
	chunk=atol(argv[1]);
	double start,end;	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	MPI_Barrier(MPI_COMM_WORLD);
	start=MPI_Wtime();
	if(rank==0){
		srand(time(0));
		for(int i=0;i<chunk*size;i++)
		{
			x[i]=rand()%1000;
		}
		printf("Number of element:%d\n",chunk*size);
	}
	MPI_Scatter(x,chunk,MPI_INT,y,chunk,MPI_INT,0,MPI_COMM_WORLD);

	// for(i=0;i<chunk;i++)
	// printf("\nValue of y in process %d : %d\n",rank,y[i]);

	int ans=y[0];
	for(int i=0;i<chunk;i++){
		if(ans>y[i])
			ans=y[i];
	}

	MPI_Reduce(&ans,&res,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);

	if(rank==0){
		end=MPI_Wtime();
		printf("\n**********Min element is : %d\n",res);
		
		printf("**********Total time taken %lf seconds\n",end-start);
	}
	MPI_Finalize();
}