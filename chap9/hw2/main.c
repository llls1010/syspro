#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pid;
	char input[99];
	char *args[99];
	char *a;

	char *k;
	int i;
	int b=0;
	int status;
	while(1)
	{
		printf("Pls input cmd : " );
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
		printf("[%d] Parent process start\n", getpid());
		
		if(input[0] == '\0')
		{
			continue;
		}

		i = 0;
		a = strtok_r(input," ",&k);
		while (a != NULL && i <= 97)
		{
			args[i++] = a;
			a = strtok_r(NULL, " ",&k);
		}
		args[i] = NULL;

		if(strcmp(args[i-1], "&") == 0)
		{
			args[i-1] = NULL;
			pid = fork();
			if (pid == 0)
			{
			printf("[%d] child process start\n",getpid());
			if (execvp(args[0], args) == -1)
			{
				exit(1);
			}
			}
			else if( pid > 0 )
			{
				waitpid(pid, &status, 0);
				printf("[%d] child process end %d\n",pid,getpid());
				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				{
					printf("Parent process end\n");
					printf("Exit\n");
					exit(1);
				}
			}
		}
		else
		{
			pid = fork();
			if(pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					exit(1);
				}
			}
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				{
					printf("Parent process end\n");
					printf("Exit\n");
					break;
				}
			}
		}
		printf("SUCCESS\n");
	}
	return 0;
}
