#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	char name[20];
};

int main()
{
	struct student *ptr;
	int n, i;

	printf("how many student would you like enter? ");
	scanf("%d",&n);
	if (n<=0)
	{
		fprintf(stderr, "error: invaild input\n");
		fprintf(stderr, "program exit");
		exit(1);
	}
	ptr = (struct student *) malloc(n *sizeof(struct student));
	if (ptr == NULL)
	{
		perror("malloc");
		exit(2);
	}

	printf("enter student number and name of %d students.\n",n);
	for (i=0;i<n;i++)
	scanf("%d %s",&ptr[i].id,ptr[i].name);

	printf("\n* student information(back) *\n");
	for(i =n-1; i>=0; i--)
	printf("%d %s\n",ptr[i].id,ptr[i].name);

	printf("\n");
	exit(0);
}
