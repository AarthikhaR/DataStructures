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
		printf("%d->",t->data);
		t = t->next;
	}
}
void del_end(NODE * head)
{
	NODE * prev;
	NODE * temp = head;
	if(temp -> next == NULL)
	{
		printf("%d element deleted !!!",temp->data);
		head = NULL;
	}
	else
	{
		while(temp -> next != NULL)
		{
			prev = temp;
			temp = temp -> next;
		}
		prev -> next = NULL;
		printf("%d element deleted !!!",temp->data);
		free(temp);
	}
	
}
int main()
{
	NODE * head;
	int i,n,ele;
	printf("\nHow many nodes do you want to create = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the elements that you want to insert = ");
		scanf("%d",&ele);
		head = push(&head,ele);
	}
	printf("\nList before Deletion: ");
	displayList(head);
	del_end(head);
	printf("\nList after Deletion: ");
	displayList(head);
}
