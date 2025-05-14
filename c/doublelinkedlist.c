#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous, *next;
};
struct node *head=NULL;
struct node *end;

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertSpecific(int value, int specific);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecific(int specific);
void displayForward();
void displayBackwards();

void main()
{
    int choice1,choice2,v,s;
    do
    {
        printf("\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
                printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert after a specific node\n4.Exit\nEnter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        printf("Enter the value to be inserted : ");
                        scanf("%d",&v);
                        insertAtBeginning(v);
                        break;
                    case 2:
                        printf("Enter the value to be inserted : ");
                        scanf("%d",&v);
                        insertAtEnd(v);
                        break;
                    case 3:
                        printf("Enter the value to be inserted : ");
                        scanf("%d",&v);
                        printf("Enter the value of specific node after which value is to be entered : ");
                        scanf("%d",&s);
                        insertSpecific(v,s);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid entry.\n");
                }
                break;
            
            case 2:
                printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete a specific node\n4.Exit\nEnter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        deleteFromBeginning();
                        break;
                    case 2:
                        deleteFromEnd();
                        break;
                    case 3:
                        printf("Enter which node to delete : ");
                        scanf("%d",&s);
                        deleteSpecific(s);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid entry.\n");
                }
                break;
            
            case 3:
                printf("\n1.From beginning to end\n2.From end to beginning\n3.Exit\nEnter your choice : ");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1:
                        displayForward();
                        break;
                    case 2:
                        displayBackwards();
                    case 3:
                        break;
                    default:
                        printf("Invalide entry.\n");
                }
                break;
            
            case 4:
                break;
            
            default:
                printf("Invalid entry.\n");
        }
    }while(choice1!=4); 
}

void insertAtBeginning(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->previous=NULL;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
        return;
    }
    temp->next=head;
    head->previous=temp;
    head=temp;
}

void insertAtEnd(int value)
{
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->previous=ptr;
}

void insertSpecific(int value, int specific)
{
    struct node *ptr, *temp;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==specific)
        {
            temp->next=ptr->next;
            temp->previous=ptr;
            ptr->next=temp;
            return;
        }
        ptr=ptr->next;
    }
    printf("\nSpecific element not present.\n");
}

void deleteFromBeginning()
{
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        head=head->next;
    }
}

void deleteFromEnd()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("Linked list is Empty.\n");
    }
    else
    {
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
    }
}

void deleteSpecific(int specific)
{
    struct node *ptr,*prev;
    ptr=head;
    if (ptr!=NULL && ptr->data==specific)
    {
        head=ptr->next;
        free(ptr);
        return;
    }
    while(ptr->next!=NULL && ptr->data!=specific)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if (ptr==NULL)
    {
        printf("Element not found.\n");
        return;
    }
    ptr->previous=prev;
    prev->next=ptr->next;
    free(ptr);
}

void displayForward()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        printf("\nThe linked list read from beginning to end is :\t");
        ptr=head;
        while(ptr->next!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\t\n",ptr->data);
    }
}

void displayBackwards()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        printf("\nThe linked list read from end to beginning is :\t");
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        while(ptr->previous!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->previous;
        }
        printf("%d\t\n",ptr->data);
    }  
}