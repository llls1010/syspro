#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct sigaction oldact;
void sigint_handler(int signo);

int main()
{
	oldact.sa_handler = sigint_handler;
	sigaction(SIGALRM, &oldact, NULL);
	alarm(5);
	short i = 0;
	while (1) {
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
}
void sigint_handler(int signo)
{
	printf("Wake up\n");
	exit(0);
}
