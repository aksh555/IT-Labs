#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
int main() {
    #pragma omp parallel num_threads(4)
    {
        int i = omp_get_thread_num();
        printf("Hello world from thread=%d\n", i) ;
    }
}    