#include <stdio.h>
#include <string.h>
#include "copy.h"

#define LINE 5
char line[LINE][MAXLINE];
char temp[MAXLINE];

int main(){
	int len,pre_len;
	int max;
	int i,j;
	max = 0;
	i = 0 ;

	while(i <=4 && gets(line[i]) != NULL){
		len = strlen(line[i]);
        
		for(j=0;j<i;j++)
		{
			pre_len = strlen(line[j]);
			if( len > pre_len)
			{
				copy(line[i], temp);
				copy(line[j], line[i]);
				copy(temp, line[j]);
			}
		}
	
		i ++;
	}
	for(i=0;i<=4;i++)
	{
		printf("%s \n", line[i]);
	}
	return 0;
}
