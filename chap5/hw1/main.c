#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i,j,fd,k;
	char savedText[10][100];
	char buf;
	char input[100];
	
	if((fd = open(argv[1], O_RDONLY)) == -1)
		perror(argv[1]);
	else printf("File read success\n");

	printf("Total Line : 4\n");

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

	printf("You can choose 1 ~ 4 Line\n");
	printf("Pls 'Enter' the line to select : ");
	k=0;
	
	fgets(input, sizeof(input), stdin);

	if(input[0] == '*')
	{
		for(i=0;i<=3;i++)
		{
			printf("%s\n",savedText[i]);
		}
	}
	else if(input[1] == '\n')
	{
		input[0] = input[0] - '0';
		printf("%s\n",savedText[input[0]-1]);
	}
	else if(input[1] == ',')
	{
		if(input[3] == ',')
		{
			if(input[5] == ',')
			{
				for(j=0;j<=3;j++)
				{
					printf("%s\n",savedText[j]);
				}
			}
			else
			{
				printf("%s\n",savedText[input[0]-'1']);
				printf("%s\n",savedText[input[2]-'1']);
				printf("%s\n",savedText[input[4]-'1']);
			}
		}
		else
		{
			printf("%s\n",savedText[input[0]-'1']);
			printf("%s\n",savedText[input[2]-'1']);
		}
	}
	else if(input[1] == '-')
	{
		for(j=input[0]-'1';j<=input[2]-'1';j++)
		{
			printf("%s\n",savedText[j]);
		}
	}
	close(fd);
	
	return 0;
}


