#include <stdio.h>
#include <stdlib.h>
static void exit_handler1(void), exit_handler2(void);

int main()
{
	if(atexit(exit_handler1) != 0)
	{
	    perror("Do not use exit_handler1.");
	}
	if(atexit(exit_handler2) != 0)
	{
	    perror("Do not use exit_hander2.");
	}
	printf("Finshed main func.\n");
	exit(0);
}

static void exit_handler1(void)
{
    printf("First Exit\n");
}

static void exit_handler2(void)
{
    printf("Second Exit\n");
}
