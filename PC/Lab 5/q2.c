#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int numThreads;
int size[] = {1000000, 5000000, 10000000};
int abs(int a)
{
    return a >= 0 ? a : -a;
}

int upper(int a, int b)
{
    if (a % b == 0)
        return a / b;
    return (a / b) + 1;
}
void swap(long int *a, long int *b)
{
    long int t = *a;
    *a = *b;
    *b = t;
}
int partition(long int arr[], int low, int high)
{
    long int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(long int arr[], int low, int high, int minSize)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        if (high - low > minSize)
        {
            #pragma omp task firstprivate(arr, low, pi)
            {
                quickSort(arr, low, pi - 1, minSize);
            }
            #pragma omp task firstprivate(arr, high, pi)
            {
                quickSort(arr, pi + 1, high, minSize);
            }
        }
        else
        {
            quickSort(arr, low, pi - 1, minSize);
            quickSort(arr, pi + 1, high, minSize);
        }
    }
}
void seq_binary_search(long int arr[], long int key, int s)
{
    double start, end;
    int loc = -1;
    int low = 0, high = size[s] - 1;
    int mid;
    start = omp_get_wtime();
    while (low <= high)
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
void par_bin_search_util(long int arr[], int key, int left, int right, int *loc)
{
    if (left > right)
    {
        return;
    }
    if (right - left <= numThreads)
    {
        int low = left, high = right, mid;
        while (low <= high)
        {
            mid = low +  (high - low) / 2 ;
            if(arr[mid] == key)
            {
                *loc = mid;
                break;
            }
            else if(arr[ mid] > key) high = mid - 1;
            else low = mid + 1 ;
        }
    }
    else
    {
        int nums = upper(right - left + 1, numThreads);
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < numThreads; i++)
        {
            if (arr[left + i * nums] <= key && arr[left + (i + 1) * nums] >= key)
            {
                #pragma omp task if (0)
                {
                    par_bin_search_util (  arr ,  key ,  left +  i  *  nums ,  left + ( i  +  1  )* nums ,  loc);
                }
            }
        }
    }
}
void par_binary_search(long int arr[], int key, int s)
{
    double start, end;
    int loc = -1;
    start = omp_get_wtime();
    par_bin_search_util(arr, key, 0, size[s] - 1, &loc);
    end = omp_get_wtime();
    printf("Time for parallel binary search = %gs \n",end - start);
}
void qsort_parallel(long int *array, int lenArray, int numThreads)
{
    int minSize = 500;
#pragma omp parallel num_threads(numThreads)
    {
#pragma omp single nowait
        {
            quickSort(array, 0, lenArray - 1, minSize);
        }
    }
}
int comp(const void *a, const void *b)
{
    return (*(long int *)a - *(long int *)b);
}
int main()
{
    long int *arr;
    numThreads = omp_get_max_threads();
    for (int s=0;s<3;s++)
    {
        srand(time(0));
        arr=(long*) calloc(size[s],sizeof(long));
        long key = arr[size[s]-1];
        printf("ArraySize = %d:\n", size[s]);
        omp_set_num_threads(omp_get_max_threads());
        qsort_parallel(arr,size[s],omp_get_max_threads());
        seq_binary_search(arr,key,s);
        par_binary_search(arr,key,s);
        free(arr);
        printf("\n");
    }
}