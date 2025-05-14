#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *link;
};
struct node *head=NULL;
int highestpriority=-1;
int size,count=0;

int isFull();
void findhighestpriority();
void insertAtEnd(int d, int p);
void delete();
void display();

void main()
{
    int choice,d,p;
    printf("Enter the size of the priority queue : ");
    scanf("%d",&size);
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data and priority : ");
                scanf("%d%d",&d,&p);
                insertAtEnd(d,p);
                break;
            
            case 2:
                delete();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                break;
            
            default:
                printf("Invalid entry.\n");
        }
    } while (choice!=4);
}

int isFull()
{
	return(size==count);
}
void findhighestpriority()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        return;
    }
    while(ptr!=NULL)
    {
        if((ptr->priority)>highestpriority)
        {
            highestpriority=ptr->priority;
        }
        ptr=ptr->link;
    }
}

void insertAtEnd(int d, int p)
{
    struct node *ptr,*temp;
    if (isFull())
    {
    	printf("Priority queue full.\n");
    	return;
    }
    temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->priority=p;
    temp->link=NULL;
    ptr=head;
    count++;
    if(head==NULL)
    {
        head=temp;
        highestpriority=p;
        return;
    }
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void delete()
{
    struct node *ptr,*prev;
    ptr=head;
    findhighestpriority();
    if (head==NULL)
    {
    	printf("Priority queue empty.\n");
    	return;
    }
    count--;
    if (ptr!=NULL && ptr->priority==highestpriority)
    {
        printf("Deleted element is : %d\n",ptr->data);
        highestpriority=-1;
        head=ptr->link;
        free(ptr);
        return;
    }
    while(ptr->link!=NULL && ptr->priority!=highestpriority)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    printf("Deleted element is : %d\n",ptr->data);
    prev->link=ptr->link;
    highestpriority=-1;
    free(ptr);
}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Priority queue is empty.\n");
    }
    else
    {
        findhighestpriority();
        printf("\nThe priority queue is :\n");
        ptr=head;
        while(ptr!=NULL)
        {
            printf("Element : %d\nPriority : %d\n\n",ptr->data,ptr->priority);
            ptr=ptr->link;
        }
    }
}
