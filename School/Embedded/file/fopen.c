#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	if ((fd = open(argv[1], O_RDWR)) == -1)
		printf("ERROR!\n");
	else printf("Succeess to open %s File! : %d\n ", argv[1], fd);

	close(fd);
	printf("\n");
	return 0;
}
