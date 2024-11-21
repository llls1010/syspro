#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node *head, struct node *tail, int data)
{
	tail ->data = data;
}
int delete(struct node *head, struct node *tail)
{
	return top->data;
}

int main()
{
	int c;
	float data;
	struct node *p, *head = NULL, *tail = NULL;
	do
	{
		c = scanf("%f",&data);
		if(c!=1)
		{
			break;
		}
		p = (struct node *) malloc(sizeof(struct node));
		p->next= tail++;
		addq(head ,p, (int)data);
	}while(data ==(int)data);
		head = head ++;
	printf("Print stack\n");
	while ( p!=NULL)
	{
		printf("%d\n",pop(p));
		p = p->next;
	}
}
