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


Node * del_inner_nodes(Node ** headref,int value) 
{
    Node * temp, * ptr;
    
    temp = *headref;
    
    while(temp -> data != value)
        temp = temp -> next;
        
    if(temp -> next == NULL)
        printf("\n Can't perform delete operation!!!");
        
    else if(temp -> next -> next == NULL)
    {
        temp -> next = NULL;
        printf("\nNode Deleted!!!");
    }
    else
    {
        ptr = temp -> next;
        temp -> next = ptr -> next;
        ptr -> next -> prev = temp;
        printf("%d deleted !!!", ptr -> data);
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
    int n,i,value;
    printf("\nHow many nodes do u want to insert = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head = push_beg(&head);
    displayList(head);
    printf("\nEnter the value after which you want to delete = ");
    scanf("%d",&value);
    head = del_inner_nodes(&head,value);
    displayList(head);
}
