#include <stdio.h>
#include <omp.h>
int main(void)
{
    unsigned int n, i, j, k, sum = 0;
    double t1, t2;
    printf("Enter the value n : ");
    scanf("%u", &n);
    unsigned int m1[n][n];
    unsigned int m2[n][n];
    unsigned int m3[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m1[i][j] = 1;
            m2[i][j] = 1;
            m3[i][j] = 0;
        }
    }
    t1 = omp_get_wtime();
#pragma omp parallel shared(n)
    {
// parallel
#pragma omp for schedule(static, 10) collapse(2) private(i, j, k, sum)
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                sum = 0;
                for (k = 0; k < n; k++)
                {
                    sum = sum + (m1[i][k] * m2[k][j]);
                }
                m3[i][j] = m3[i][j] + sum;
            }
        }
    }
    t2 = omp_get_wtime();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%u ", m3[i][j]);
        }
        printf("\n");
    }
    printf("\nTime taken for execution in parallel is %f s \n", t2 - t1);
    return 0;
}