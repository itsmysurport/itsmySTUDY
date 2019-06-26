#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid1, pid2, child, status;
    
    printf("[%d] Parents Process start. \n", getpid());
    pid1 = fork();
    if(pid1 == 0)
    {
	printf("[%d] Other process start. \n", getpid());
	sleep(1);
	printf("[%d] Other process Ended. \n", getpid());
	exit(1);
    }
    pid2 = fork();
    if(pid2 == 0)
    {
	printf("[%d] Other process start. \n", getpid());
	sleep(1);
	printf("[%d] Other process Ended. \n", getpid());
	exit(2);
    }
    child = waitpid(pid1, &status, 0);
    printf("[%d] Other Process %d ended \n",getpid(), child);
    printf("\t Finished Code %d\n", status>>8);
}
