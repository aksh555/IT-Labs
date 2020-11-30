#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int pfds1[2],pfds2[2];
    int n, f = 1, i, n1, x, y;
    printf("Parent: Enter the number ");
    scanf("%d",&n);
    x=n-1;
    pipe(pfds1);
    pipe(pfds2);
    write(pfds1[1], (char *)&x, sizeof(x));
    close(pfds1[1]);
    printf("Parent: Sending %d to the child\n", x);
    if (!fork())
    {
        read(pfds1[0], &y, sizeof(int));
        close(pfds1[0]);
        printf("Child: Read %d from parent\n",y);
        printf("Child: Writing fact value to the Pipe \n");
        for (i = 1; i <= y; i++)
            f = f * i;
        write(pfds2[1], (char *)&f, sizeof(f));
        close(pfds2[1]);
        printf("Child: Exiting\n");
    }
    else
    {
        wait(0);
        read(pfds2[0], &n1, sizeof(int));
        printf("Parent: Read %d from the pipe\n",n1);
        printf("Parent: Factorial of %d is: %d\n",n,n1*n);
        sleep(1);
        close(pfds2[0]);
    }
    return 0;
}