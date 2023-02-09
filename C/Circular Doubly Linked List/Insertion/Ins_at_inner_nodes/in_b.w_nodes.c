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

Node * push_inner_nodes(Node ** headref,int val)
{
    int new_data;
    
    Node * new_node = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data to be inserted = ");
    scanf("%d",&new_data);
    new_node -> data = new_data;

    Node * temp = *headref;
    while(temp -> data != val)
        temp = temp -> next;
    
    new_node -> next = temp -> next;
    temp -> next -> prev = new_node;
    new_node -> prev = temp;
    temp -> next = new_node;
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
int main()
{
    Node * head =NULL;
    int i,n,val;
    printf("\nHow many nodes do you want to create = ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        head = push_end(&head);
    }
    displayList(head);
    printf("\nEnter the value of node after which you want to insert = ");
    scanf("%d",&val);
    head = push_inner_nodes(&head,val);
    displayList(head);
}
