#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 80

int main(int argc, char *argv[])
{
	FILE *fp;
	int line =0;
	char buffer[MAXLINE];
	char c;
	int i=0;
	char c1[100];
	int s=0;
	int len=0;
	int len1=0;
	int j;
	int k=0;

	if (argc <= 2)
	{
	
		if ( (fp = fopen(argv[1],"r")) == NULL)
		{
			fprintf(stderr, "Error Open File\n");
			exit(2);
		}

		while(fgets(buffer,MAXLINE,fp) != NULL)
		{
			line++;
			printf("%s",buffer);
			if (line ==2)
				break;
		}
	exit(0);
	}
	else 
	{
		fp = fopen(argv[2],"r");
		while((c = fgetc(fp)) != EOF)
		{  
			if( c== '\n')
			{
				if (len1 == 1)
				{
					for(i=0;i<k;i++)
					{
						printf("%c",c1[i]);
					}
				}
				len1=0;
				k=0;
			}
			c1[k] = c;
			k++;
			if (s != 0 && c == argv[1][s])
			{
				s++;
			}
			else if (s == 0 && c == argv[1][0])
			{
				len = strlen(argv[1]);
				s++;
			}
			else if(s == len && s != 0)
			{
				len1 =1;
				s = 0;
			}
			else
			{
				s = 0;
			}

		}
	}
}
