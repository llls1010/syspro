#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i,j;
	int fd;
	char savedText[10][100];
	char buf;
	
	if((fd = open(argv[1], O_RDONLY)) == -1)
		perror(argv[1]);

	for(i = 0; i <= 3; i++)
	{
		j=0;
		while(read(fd, &buf, 1) > 0 )
		{
			if(buf == '\n')
			{
				savedText[i][j]='\0';
				break;
			}
			savedText[i][j++]=buf;
		}
	}
	for(j=3;j>=0;j--)
	{
		printf("%s\n",savedText[j]);
	}
	close(fd);
	
	return 0;
}


