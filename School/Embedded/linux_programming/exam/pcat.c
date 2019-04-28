#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	int i;
	char *CH = (char*) malloc(sizeof(char) * 64);

	if( argc < 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
	}

	if((fd=open(argv[1], O_RDWR)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}
	read(fd, CH, BUFSIZ);
	
	printf("%s\n", CH);

	close(fd);
	return 0;
}
