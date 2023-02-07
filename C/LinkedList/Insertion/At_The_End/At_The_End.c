#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

void displayLinkedList(NODE * head)
{
	NODE * n = head;
	printf("\n\n Complete Linked List that you've created : \n");
	
	while(n != NULL)
	{
		printf(" %d -> ",n->data);
		n = n->next;
	}
	printf("NULL\n");
}
void insAtEnd(NODE ** head,int n)
{
	int i;
	for(i = 0;i < n; ++i)
	{
		NODE * new_node = (NODE*)malloc(sizeof(NODE*));
		printf("\nEnter the data that you want to insert = ");
		scanf("%d",&new_node->data);
		new_node -> next =  NULL;
		
		if(*head == NULL)
		{
			*head = new_node;
		}
		else
		{
			NODE * last = *head;
			while(last-> next!= NULL)
			{
				last = last->next;
			}
			last->next = new_node;
		}
		printf("Element %d created!!!",new_node->data);
	}
}

int main()
{
	int n;
	NODE * HEAD;
	printf("\nHow many nodes you want to insert = ");
	scanf("%d",&n);
	insAtEnd(&HEAD,n);
	displayLinkedList(HEAD);
}
