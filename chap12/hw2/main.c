#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define READ 0
#define WRITE 1

int main(int argc, char* argv[])
{
	char str[1024];
	int fd[2];

 pipe(fd);

 printf("parent process start\n");

 if ( fork() == 0)
 {
	 close(fd[READ]);
	 printf("input string: ");
	 fgets(str, sizeof(str), stdin);
	 str[strcspn(str, "\n")] = '\0';

	 write(fd[WRITE],str,strlen(str) +1);
 	 close(fd[WRITE]);
	 exit(0);
 }
 else {
	 if (fork() == 0)
	 {
		 close(fd[WRITE]);
		 char str1[1024];

		 read(fd[READ],str1,1024);
		 for(int i = 0; str1[i] !='\0'; i++)
		 {
			 if( str1[i] > 96 && str1[i] <123)
			 {
			 str1[i] = str1[i] - 32;
		  	 }
		 }

		 printf("%s\n",str1);
		 close(fd[READ]);
		 exit(0);
	 }
	 else{
		 wait(NULL);
		 wait(NULL);
}
}
return 0;
}
