#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	static struct flock lock;
	int fd, ret, c;
	if(argc < 2)
	{
		fprintf(stderr, "USAGE: %s File\n", argv[0]);
		exit(1);
	}
	fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		printf("FAILED TO OPEN\n");
		exit(1);
	}

	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	lock.l_pid = getpid();
	ret = fcntl(fd, F_SETLKW, &lock);
printf("ret=%d\n", ret);
	if(ret == 0)
	{
		c = getchar();
	}
	return 0;
}
