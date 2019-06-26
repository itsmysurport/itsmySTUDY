// This programi about File Desciptor I created myself.

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0;
    if(argc != 2)
    {
	fprintf(stderr, "USAGE: %s file1\n", argv[0]);
	return 1;
    }

    fp = fopen(argv[1], "r");
    
    while(!(feof(fp)))
    {
	fgetc(fp);
	i++;
    }
    printf("%d\n", i);

    return 0;
}
