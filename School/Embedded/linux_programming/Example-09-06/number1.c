#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo);

int main(void)
{
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask);
	
	// SIGINT run "newact.sa_handler" and saved previous handler in oldact
	sigaction(SIGINT, &newact, &oldact);

	while(1)
	{
		printf("Press SIGNAL INTERRUPT using 'CTRL + C' \n");
		sleep(1);
	}
}

/* NEW SIGNAL INTERRUPT FUNCTION */

void sigint_handler(int signo)
{
	int fd;
	char *msg = "DETECTED INTERRUPT. SAVE ERROR FILE IN THIS DIRECTORY!\n";
	printf(msg);
	fd = open("errorFile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(fd == -1)	exit(1);
	write(fd, msg, strlen(msg));
	sigaction(SIGINT, &oldact, NULL);
	close(fd);
}
