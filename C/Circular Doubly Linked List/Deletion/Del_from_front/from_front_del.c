#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}Node;

Node * push_end(Node ** headref)
{
    int new_data;
    
    Node * new_node = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data to be inserted = ");
    scanf("%d",&new_data);
    new_node -> data = new_data;
    
    if(*headref == NULL)
    {
        *headref = new_node;
        new_node -> next = *headref;
        new_node -> prev = *headref;
    }
    else
    {
        Node * temp = *headref;
        while(temp -> next != *headref)
            temp = temp -> next;
        temp -> next = new_node;
        new_node -> prev = temp;
        new_node -> next = *headref;
        (*headref) -> prev = new_node;
    }
    return *headref;
}

void displayList(Node * head)
{
    int n =1;
    Node * t = head;
    printf("\n");
    do
    {
        printf("\nNode %d : %d",n,t->data);
        t = t -> next;
        n++;
    }while(t != head);
    printf("\n");
}

Node * del_front(Node ** headref)
{
	if((*headref) -> next == *headref)
	{
		*headref = NULL;
		free(*headref);
		printf("Element %d deleted!!!",(*headref)->data);
	}
	else
	{
		Node * temp = *headref;
		while(temp -> next != *headref)
		{
			temp = temp -> next;
		}
		temp -> next = (*headref)->next;
		temp -> next -> prev = temp;
		printf("Element %d deleted !!!",(*headref) -> data);
		free(*headref);
		*headref = temp -> next;
	}
	return *headref;
}

int main()
{
    Node * head =NULL;
    int i,n;
    printf("\nHow many nodes do you want to create = ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        head = push_end(&head);
    }
    displayList(head);
    head = del_front(&head);
    displayList(head);
}
