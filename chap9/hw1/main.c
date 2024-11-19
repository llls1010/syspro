#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	int pid;
	int fd;
	char in[99];
	if(argc <3)
	{
	char *commands = strtok(argv[1], ";");
	while (commands != NULL)
	{
		char *args[] = {commands, NULL};
		execvp(commands, args);
		commands = strtok(NULL,";");
	}
	}
	else if (argv[2] == "&")
	{
		pid = fork();
		if (pid == 0)
		{
		execvp(argv[1], &argv[1]);
		}
	}
	else if (argc == 4 )
	{
		if(argv[2] == "<")
		{
			fd = open(argv[3], O_RDONLY);
			dup2(fd, 1);
			close(fd);
			execvp(argv[1], &argv[1]);
		}
		else if(argv[2] == ">")
		{
			fd = open(argv[3], O_CREAT|O_TRUNC|O_WRONLY,0600);
			dup2(fd, 1);
			close(fd);
			execvp(argv[1], &argv[1]);
		}
	}
}
