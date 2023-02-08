#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node * push_beg(Node ** headref,int n)
{
    int i,new_data;
    for(i=0;i<n;i++)
    {
        Node * new_node = (Node*)malloc(sizeof(Node));
        printf("\nEnter the data to be inserted : ");
        scanf("%d",&new_data);
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
    int new_data,i,n;
    printf("\nHow many nodes do u wamt to insert = ");
    scanf("%d",&n);
    head = push_beg(&head,n);
    displayList(head);
}
