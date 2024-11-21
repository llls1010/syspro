#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node *top, int data)
{
	top -> data = data;
}
int pop(struct node *top)
{
	return top->data;
}

int main()
{
	int c;
	float data;
	struct node *p, *head = NULL;
	do
	{
		c = scanf("%f",&data);
		if(c!=1)
		{
			break;
		}
		p = (struct node *) malloc(sizeof(struct node));
		push(p, (int)data);
		p->next = head;
		head = p;
	}while(data ==(int)data);
		p = head;
	printf("Print stack\n");
	while ( p!=NULL)
	{
		printf("%d\n",pop(p));
		p = p->next;
	}
}
