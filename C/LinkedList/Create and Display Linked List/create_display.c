#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node *ptr;
}node;

node * createLinkedList(int n)
{
	int i;
	node * head = NULL;
	node * temp = NULL;
	node * p = NULL;
	
	for(i=0;i<n;i++)
	{
		temp = ((node*) malloc(sizeof(node))); 
		printf("\nEnter the data for node number %d : ",i+1);
		scanf("  %d", &(temp->num));
		temp->ptr = NULL;
		
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			p = head;
			while(p->ptr != NULL)
				p = p -> ptr;
			p->ptr = temp;
		}
	}
	return head;
}

void displayLinkedList(node * head)
{
	node * p = head;
	while(p != NULL)
	{
		printf("%d->",p->num);
		p=p->ptr;
	}
} 
int main()
{
	int n;
	node *HEAD;
	printf("\nEnter the no of nodes = ");
	scanf("%d",&n);
	HEAD = createLinkedList(n);
	displayLinkedList(HEAD);	
} 
