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
	printf("NULL\n");
	
}
void insAtMiddle(NODE **headref,int n)
{
	int i,new_data,pos,loc;
	for(i = 0;i < n;++i)
	{
		printf("\nEnter the data that you want to insert = ");
		scanf("%d",&new_data);
		printf("\nEnter the position at which you want to insert = ");
		scanf("%d",&pos);
		loc = pos;
		pos--;

		NODE * new_node = (NODE *)malloc(sizeof(NODE*));
		new_node -> data = new_data;
		new_node -> next = NULL;
		
		if(pos == 0)
		{
			new_node -> next = *headref;
			*headref = new_node;
		}
		else
		{
			NODE * ptr = *headref;
			
			while(pos != 1) 
			{
				ptr = ptr -> next;
				pos--;
			}
			new_node -> next = ptr->next;
			ptr -> next = new_node;
			
		}
		printf("\n Element %d inserted at position %d !!!",new_data,(loc));
	}
}

int main()
{
	int n;
	NODE * head=NULL;
	printf("\nHow many nodes you want to insert = ");
	scanf("%d",&n);
	insAtMiddle(&head,n);
	displayLinkedList(head);
}
