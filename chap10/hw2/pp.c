#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data = data;
	p-> next = NULL;
	if(*tail== NULL)
	{
		*head = *tail=p;
	}
	else
	{
		(*tail)->next = p;
		*tail=p;
	}
	
}
int delete(struct node **head, struct node **tail)
{
	struct node *p = *head;
	int data = p ->data;
	*head = (*head)->next;
	free(p);
	return data;
}

int main()
{
	int c;
	float data;
	struct node *head = NULL, *tail = NULL;
	do
	{
		c = scanf("%f",&data);
		if(c!=1)
		{
			break;
		}
		addq(&head, &tail,(int)data);
	}while(data ==(int)data);

	printf("Print queue\n");
	while ( head!=NULL)
	{
		printf("%d\n",delete(&head,&tail));
	}
}
