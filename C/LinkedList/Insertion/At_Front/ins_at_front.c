#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

void displayLinkedList(NODE * head)
{
	NODE * ptr = head;
	printf("\n\n Complete Linked List that you've created : \n");
	while(ptr != NULL)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	
}
void insAtFront(NODE **headref,int n)
{
	int i,new_data;
	for(i = 0;i < n;++i)
	{
		printf("\nEnter the data that you want to insert = ");
		scanf("%d",&new_data);
		NODE * new_node = (NODE *)malloc(sizeof(NODE*));
		new_node -> data = new_data;
		new_node -> next = *headref;
		*headref = new_node;
		printf("\n Element %d inserted!!!",new_data);
	}
}

int main()
{
	int n;
	NODE * head = NULL;
	printf("\nHow many nodes you want to insert = ");
	scanf("%d",&n);
	insAtFront(&head,n);
	displayLinkedList(head);
}
