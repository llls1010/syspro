#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
 char str[1024];
 str[0] = '\0';
 for (int i = 1; i <argc; i++)
 {
	 strcat(str, argv[i]);
	 if ( i < argc -1)
	 {
		 strcat(str," ");
	 }
 }
 printf("%s\n",str);
}
