#include <unistd.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

void dontDisturb();

int main()
{
	sigset_t set;
	int count = 5;
	signal(SIGINT, dontDisturb);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, NULL);

	while(count)
	{
		printf("don't disturb me (%d)\n", count--);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &set, NULL);
	while(1)
		pause();
	return 0;
}

void dontDisturb()
{
	printf("Distrub me!\n");
	exit(0);
}
