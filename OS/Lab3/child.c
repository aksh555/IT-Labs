#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    
int main (int argc, char **argv)
{   
    int i, j;
    long sum;

    printf ("Child: Hello World!\n");

    for (i = 0; i < 10; i++ ) {
        for (j =0; j < 1000; j++) {
            sum = 100 * i + 200*j;
            // sum/=0; causes error in child program
        }
    }

    printf ("Child: Work completed!\n");
    printf ("Child: Exiting\n");

    exit (0);
}