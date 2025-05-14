#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;

int size,count=0;
int isFull();
void insertAtEnd(int value);
void deleteFromBeginning();
void display();

void main()
{
    int choice,v;
    printf("Enter the size of the queue : ");
    scanf("%d",&size);
    do
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted : ");
                scanf("%d",&v);
                insertAtEnd(v);              
                break;
            
            case 2:
                deleteFromBeginning();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                break;
            
            default:
                printf("Invalid entry.\n");
        }
    }while(choice!=4); 
}

int isFull()
{
    return(count==size);
}

void insertAtEnd(int value)
{
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    count++;
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if (head==NULL)
    {
        head=temp;
        return;
    }
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    
}

void deleteFromBeginning()
{
    if(head==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        head=head->link;
    }
}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("\nThe queue is :\t");
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("%d\t\n",ptr->data);
    }
}