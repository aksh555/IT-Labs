#include <stdio.h>
#include <omp.h>
int main(void)
{
    unsigned int n, i, j;
    double t1, t2;
    printf("Enter the value n : ");
    scanf("%u", &n);
    unsigned int m[n][n];
    unsigned int rsum[n];
    unsigned int csum[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j % 2 == 0)
                m[i][j] = 2;
            else if (i % 2 == 0)
                m[i][j] = 3;
            else m[i][j] = 1;
        }
    }
    t1 = omp_get_wtime();
    for (i = 0; i < n; i++)
    {
        int ans = 0;
        for (j = 0; j < n; j++)
        //row sum
        {
            ans += m[i][j];
        }
        rsum[i] = ans;
    }
    for (i = 0; i < n; i++)
    {
        int ans = 0;
        for (j = 0; j < n; j++)
        //column sum
        {
            ans += m[j][i];
        }
        csum[i] = ans;
    }
    t2 = omp_get_wtime();
    printf("Row Sum : \n");
    for (i = 0; i < n; i++)
    {
        printf("Row %u : %u \n", i, rsum[i]);
    }
    printf("\nColumn Sum : \n");
    for (i = 0; i < n; i++)
    {
        printf("Column %u : %u \n", i, csum[i]);
    }
    printf("\nTime taken for execution in sequence is %fs \n", t2 - t1);
    return 0;
}