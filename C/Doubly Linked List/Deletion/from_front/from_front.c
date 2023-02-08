#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node * push_beg(Node **headref)
{
    int new_data;
    printf("\nEnter the data to be inserted = ");
    scanf("%d",&new_data);
    
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
     
    if(*headref == NULL)
        *headref = new_node;
    else
    {
        new_node -> next = *headref;
        new_node -> prev = NULL;
        (*headref) -> prev = new_node;
        *headref = new_node;
    }
    return *headref;
}


Node * del_beg(Node ** headref) 
{
        
    if((*headref) -> next == NULL)
    {
        *headref = NULL;
        printf("\nElement %d is deleted!!!",(*headref)->data);
        free(*headref);
    }
    
    else
    {
        Node * ptr = *headref;
        printf("\nElement %d is deleted!!!",(*headref)->data);
        *headref = (*headref) -> next;
        (*headref) -> prev = NULL;
        free(ptr);
    }
    return *headref;
}

void displayList(Node * head)
{
    int n=1;
    Node * t = head;
    printf("\n");
    while(t != NULL)
    {
        printf("\nnode %d : %d ",n,t->data);
        t = t->next;
        n++;
    }
    printf("\n");
}
int main()
{
    Node * head = NULL;
    int n,i,pos;
    printf("\nHow many nodes do u want to insert = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head = push_beg(&head);
    displayList(head);
    head = del_beg(&head);
    displayList(head);
}
