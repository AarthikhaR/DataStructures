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

void search_recur(struct node * temp,int key,int count)
{
    if(temp -> data == key)
    	printf("%d found at position %d !!!",key,count+1);
    if(temp -> next == NULL)
    	return;
    search_recur( temp->next , key , (++count) );
}
int main()
{
	struct node * head = NULL;
	int i,n,key,count = 0;
	printf("\nHow many elements do you want to insert = ");
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		head = push_end(&head);
	}
	displayList(head);
	printf("\nEnter the key which you want to search = ");
	scanf("%d",&key);
	search_recur(head , key , count);
}
