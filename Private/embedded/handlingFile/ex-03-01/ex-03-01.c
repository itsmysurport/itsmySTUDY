#include <sys/types.h>
#include <fcntl.h>	//file descriptor
#include <unistd.h>

void main()
{
	int filedes, fdnew1, fdnew2;
	ssize_t nread;			// equal signed int
	off_t newpos;			// equal long

	char buffer[1024];
	char content[] = "Hello my friend!!\n";

	filedes = open("data.txt", O_RDWR);	// Open to Read and Write

	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	write(filedes, content, strlen(content));

	newpos = lseek(filedes, (off_t)0, SEEK_SET);	//Set cursor position
	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	close(filedes);

	fdnew1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);	//File access permissions (rw-r--r--)
	fdnew2 = creat("newdata2.txt", 0644);			//File access permissions (rw-r--r--)

	close(fdnew1);		close(fdnew2);
	unlink("newdata2.txt");					//Delete newdata2.txt
}
