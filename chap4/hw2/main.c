#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;
	char lin[256][256];
	int n;

	for(int i=1;i<argc;i++)
	{
		if(argv[i][0] == '-')
		{
			if(argv[i][1] == 'n')
				n=1;
		}
		else
		{
			fp = fopen(argv[i],"r");
			fgets(lin[i],sizeof(lin),fp);
		}
	}

	for(int i=1;i<argc;i++)
	{
		if(i==1&&n==1)
			i+=1;
		if(n==1)
			printf("%3d ",i-1);
		printf("%s",lin[i]);
	}
	fclose(fp);
	return 0;
}
