#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1

int main(int argc, char* argv[])
{
	char str[1024];
	char *command1=NULL,*command2=NULL;
	int fd[2];
	
	if (argc > 1)
	{
		snprintf(str, sizeof(str), "%s", argv[1]);
		for(int i = 2; i < argc; i++)
		{
			strncat(str, " ", sizeof(str) - strlen(str) - 1);
			strncat(str, argv[i], sizeof(str) - strlen(str) -1);
		}
	}
	else
	{
	printf("[shell]");
	fgets(str,sizeof(str),stdin);
	str[strlen(str)-1]='\0';
	}
	if(strchr(str,'|')!=NULL)
	{
		command1=strtok(str,"| ");
		command2=strtok(NULL,"| ");
	}
	
	pipe(fd);

	if(fork() ==0)
	{
		close(fd[READ]);
		dup2(fd[WRITE],STDOUT_FILENO);
		close(fd[WRITE]);
		execlp(command1,command1,NULL);
		perror("pipe");
	}
	if ( fork() == 0)
	{
		close(fd[WRITE]);
		dup2(fd[READ],STDIN_FILENO);
		close(fd[READ]);
		execlp(command2,command2,NULL);
		perror("pipe");
	}
	close(fd[READ]);
	close(fd[WRITE]);
	wait(NULL);
	wait(NULL);
}
