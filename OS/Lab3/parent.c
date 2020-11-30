#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    int i = 0;
    long sum;
    int pid;
    int status, ret;
    char *myargs [] = { NULL };
    char *myenv [] = { NULL };

    printf ("Parent: Hello World!\n");

    pid = fork ();

    if (pid == 0) {

        // child
        printf("child process pid = %u\n",getpid()); 
        execve ("child", myargs, myenv);
    }

    // parent
    printf("parent process pid = %u\n",getppid());
    printf ("Parent: Waiting for Child to complete.\n");

    if (waitpid(pid, &status, 0) > 0) { 
			
			if (WIFEXITED(status) && !WEXITSTATUS(status)) 
			printf("child program executed successfully!\n"); 
			
			else if (WIFEXITED(status) && WEXITSTATUS(status)) { 
				if (WEXITSTATUS(status) == 127) { 

					// execv failed 
					printf("execv failed\n"); 
				} 
				else
					printf("child program terminated normally,"
					" but returned a non-zero status\n");				 
			} 
			else
			printf("child program didn't terminate normally!\n");			 
		} 
		else { 
		// waitpid() failed 
		printf("waitpid() failed!\n"); 
		} 
	exit(0); 
}