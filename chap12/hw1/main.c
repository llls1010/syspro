#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

int main()
{
	int n, length, fd[2], pid;
	char message[MAXLINE], line[MAXLINE];

	pipe(fd);
	if ((pid = fork()) == 0 )
	{
		close (fd[0]);
		sprintf(message, "Hello from PID %d", 1101);
		length = strlen(message) + 1;
		write(fd[1], message, length);
		printf("Send : [%d] %s\n", 1101, message);
	}
	else {
		close(fd[1]);
		wait(NULL);
		n = read(fd[0], line, MAXLINE);
		printf("Recv : [%d] %s\n", 100, line);
	}
	exit(0);
}
