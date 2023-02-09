#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

struct node* push_end(struct node ** headref)
{
	int new_data;
	
	struct node * newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data to be inserted = ");
	scanf("%d",&new_data);
	newnode -> data = new_data;
	newnode -> next = NULL;
	
	if(*headref == NULL)
	{
		*headref = newnode;
	}
	
	else
	{
		struct node * temp = *headref;
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = newnode;
	}
	return *headref;
}

void displayList(struct node * head)
{
	struct node * t = head;
	while(t != NULL)
	{
		printf("%d -> ",t->data);
		t = t -> next;
	}
	printf(" NULL");
}

void search(struct node ** head,int key)
{
	struct node * temp = *head;
	int count = 0;
	while(temp != NULL)
	{
		if(temp -> data == key)
		{
				printf("%d found at position %d",temp->data,count+1);
		}
		temp = temp -> next;
		count++;
	}
}
int main()
{
	struct node * head = NULL;
	int i,n,key;
	printf("\nHow many elements do you want to insert = ");
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		head = push_end(&head);
	}
	displayList(head);
	printf("\nEnter the key which you want to search = ");
	scanf("%d",&key);
	search(&head , key);
}
