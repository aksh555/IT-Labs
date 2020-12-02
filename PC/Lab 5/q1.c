#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

int size[]  = {10000, 100000, 1000000, 10000000, 100000000};

void seq_linear_search(int arr[], int key, int s)
{
    double start, end;
    int loc = - 1 ;
    start = omp_get_wtime();
    for(int i = 0;  i < size[s]; i ++)
    {
        if(arr[i] == key)
        {
            loc = i ;
            break;
        }
    }
    end = omp_get_wtime();
    printf("Time for sequential linear search = %gs \n",end - start);
}

void par_linear_search(int arr[] , int key, int s)
{
    double start, end;
    int loc;
    start = end = 0 ;
    loc = - 1 ;
    start =  omp_get_wtime();
#pragma omp parallel for
    for(int i=0;i<size[s];i++)
    {
        if(arr[i]==key) loc = i ;
    }
    end = omp_get_wtime();
    printf("Time for parallel linear search = %gs \n",end - start);
}

void seq_binary_search(int arr[],int key,int s)
{
    double start, end;
    int loc = -1;
    int low = 0, high = size[s] - 1;
    int mid;
    start = omp_get_wtime();
    while(low <= high)
    {
        mid = low +  (high - low) / 2 ;
        if(arr[mid] == key)
        {
            loc = mid;
            break;
        }
        else if(arr[ mid] > key) high = mid - 1;
        else low = mid + 1 ;
    }
    end = omp_get_wtime();
    printf("Time for sequential binary search = %gs \n",end - start);
}

int comp(const void*a,const void*b)
{
    return(*(int*)a-*(int*)b);
}

int main()
{
    int *arr;
    for(int s=0;s<5;s++)
    {
        srand(time(0));
        arr = (int*) calloc( size[s], sizeof(int));
        for(int i = 0 ;i < size[s];i++) arr[i] = rand();
        int key = arr[size[s]-1];
        printf("ArraySize = %d:\n", size[s]); 
        seq_linear_search(arr,key,s);
        par_linear_search(arr,key,s);
        qsort(arr,size[s],sizeof(int),comp);
        seq_binary_search(arr,key,s);
        free(arr);
        printf("\n");
    }
}