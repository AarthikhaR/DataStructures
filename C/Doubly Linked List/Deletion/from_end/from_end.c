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


Node * del_end(Node ** headref) 
{
    Node * temp = *headref;
    
    if(*headref == NULL)
        printf("\nUNDERFLOW!!!");
    else if((*headref) -> next == NULL)
    {
        *headref = NULL;
        free(*headref);
        printf("\nNode deleted!!!");
    }
    else
    {
        while(temp -> next != NULL)
            temp = temp->next;
        temp -> prev -> next = NULL;
        printf(" %d is deleted !!!",temp -> data);
        free(temp);
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
    head = del_end(&head);
    displayList(head);
}
