#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid, child, status;
    printf("[%d] Parents Process start. \n", getpid());
    pid = fork();
    if(pid == 0)
    {
	printf("[%d] Other process start. \n", getpid());
	exit(1);
    }
    child = wait(&status);
    printf("[%d] Other Process %d ended \n",getpid(), child);
    printf("\t Finished Code %d\n", status>>8);
}
