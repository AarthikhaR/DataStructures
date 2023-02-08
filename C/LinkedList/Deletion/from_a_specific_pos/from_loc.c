#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE * push(NODE * head,int ele)
{
	NODE * temp = NULL;
	
	NODE * new_node = (NODE*)malloc(sizeof(NODE*));
	new_node->data = ele;
	new_node->next = NULL;
	
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
			temp = temp -> next;
		temp->next = new_node;
	}
	return head;
}
void displayList(NODE * t)
{
	while(t != NULL)
	{
	    if(t -> next == NULL)
	        printf("%d -> NULL",t->data);
	    else
		    printf("%d->",t->data);
		t = t->next;
	}
}
void del_pos(NODE * ptr,int pos)
{
	int i;
	NODE * temp = ptr;
	for(i=0;i<pos-1;i++)
		temp = temp -> next;
	NODE * del = temp -> next;
	temp->next = temp->next->next;
	del->next = NULL;
	free(del);
}
int main()
{
	NODE * head;
	int i,n,ele,pos;
	printf("\nHow many nodes do you want to create = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the elements that you want to insert = ");
		scanf("%d",&ele);
		head = push(head,ele);
	}
	printf("\nList before Deletion: ");
	displayList(head);
	printf("\nEnter the position after which deletion has to be performed = ");
	scanf("%d",&pos);
	del_pos(head,pos);
	printf("\nList after Deletion: ");
	displayList(head);
}
