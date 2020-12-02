// Add 2 arrays parallely

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    int i, n, chunk;
    int a[20], b[20], c[20];
    n = 20;
    chunk = 8;

    // initializing array
    for (i=0;i<n;i++)
    {
        a[i]=i*2;
        b[i]=i*3;
    }
    omp_set_num_threads(3);
    #pragma omp parallel
    {
        #pragma omp for schedule(static,chunk)
        for (i=0;i<n;i++)
        {
            c[i]=a[i]+b[i];
            printf("Thread id=%d i=%d,c[%d]=%d\n", omp_get_thread_num(), i, i, c[i]);
        }
        printf("Execution %d", omp_in_parallel());
    }
}