#include <stdio.h>

int main()
{
    printf("Parent Process started\n");
    if(fork() == 0)
    {
	execl("/bin/echo", "echo", "hello", NULL);	// Other Process ended here.
	fprintf(stderr, "First Failed.");
	printf("GI\n");
	exit(1);
    }
    printf("Parent Process ended!\n");
}
