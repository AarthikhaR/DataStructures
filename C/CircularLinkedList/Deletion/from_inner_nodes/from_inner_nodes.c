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
   
     
    if(*headref == NULL)
    {
        *headref = new_node;
        new_node -> next = *headref;
    }
    
    else
    {
        Node *temp = *headref;
        while(temp -> next != *headref)
            temp = temp->next;
        new_node -> next = *headref;
        temp -> next = new_node;
        *headref = new_node;
    }
    return *headref;
}

Node * del_inner_nodes(Node ** headref , int val)
{
    Node * temp = *headref;
    
    while(temp -> data != val)
        temp = temp -> next;
    Node * del_node = temp -> next;
    if(temp -> next -> next == *headref)
    {
        temp -> next = *headref;
        free(del_node);
    }
    else
    {
     temp -> next = del_node -> next;
     free(del_node);
    }
    return *headref;
}

void displayList(Node * head)
{
    int n=1;
    Node * t = head;
    printf("\n");
    do
    {
        printf("\nnode %d : %d ",n,t->data);
        t = t->next;
        n++;
    }while(t != head);
    printf("\n");
}

int main()
{
    Node * head = NULL;
    int n,i,val;
    printf("\nHow many nodes do you want to insert = ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head = push_beg(&head);
    displayList(head);
    printf("\nEnter the value of node after which you want to perform deletion =  ");
    scanf("%d",&val);
    head = del_inner_nodes(&head,val); 
    displayList(head);
}
