#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char **ptr;
	char *aptr;
	extern char **environ;
	int e=0, u=0, g=0, i=0, p=0;
	
	if(argv[1][0] == '-')
	{
		if(argv[1][1] == 'e')
			e++;
		else if(argv[1][1] == 'u')
			u++;
		else if(argv[1][1] == 'g')
			g++;
		else if(argv[1][1] == 'i')
			i++;
		else if(argv[1][1] == 'p')
			p++;
	}

	if(e==1)
	{
		if(argc < 3 )
		{
			for (ptr = environ; *ptr != 0; ptr++)
				printf("%s \n", *ptr);
		}
		else 
		{
			aptr = getenv(argv[2]);
			printf("%s = %s \n",argv[2], aptr);
		}
	}
	else if(u==1)
	{
		printf("my realistic user id: %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
		printf("my vaild user id: %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
	}
	else if(g==1)
	{
		printf("my realistic group id: %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
		printf("my vaild group id: %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
	}
	else if(i==1)
	printf("my process number : [%d]\n", getpid());
	else if(p==1)
	printf("my parent process num : [%d]\n",getppid());
}
