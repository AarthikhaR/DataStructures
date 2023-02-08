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


Node * push_bw_nodes(Node ** headref,int pos)
{
    int j,new_data;
    printf("\nEnter the data to be inserted : ");
    scanf("%d",&new_data);
        
    if(pos == 0)
        *headref = push_beg(*(&headref));
            
    else
    {
        Node * temp = *headref;
            
        Node * new_node = (Node*)malloc(sizeof(Node));
        new_node->data = new_data;
        new_node->next = NULL;
            
        while(--pos)
            temp = temp -> next;   
        Node * temp2 = temp->next;
        new_node -> next = temp -> next;
        new_node -> prev = temp;
        temp -> next = new_node;
        if(new_node -> next !=NULL)
                temp2 ->prev = new_node;
        }
    return *headref;
}

void displayList(Node * head)
{
    int n=1;
    Node * t = head;
    while(t != NULL)
    {
        printf("\nnode %d : %d ",n,t->data);
        t = t->next;
        n++;
    }
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
    printf("\nEnter the position at which you want to insert = ");
    scanf("%d",&pos);
    head = push_bw_nodes(&head,pos);
    displayList(head);
}
