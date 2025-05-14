#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertSpecific(int value, int specific);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecific(int specific);
void display();

void main()
{
    int choice1,choice2,v,s;
    do
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice : ");
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
                display();
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
    temp->link=head;
    head=temp;
}

void insertAtEnd(int value)
{
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
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
            temp->link=ptr->link;
            ptr->link=temp;
            return;
        }
        ptr=ptr->link;
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
        head=head->link;
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
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=NULL;
    }
}

void deleteSpecific(int specific)
{
    struct node *ptr,*prev;
    int flag=0;
    ptr=head;
    if (ptr!=NULL && ptr->data==specific)
    {
        head=ptr->link;
        free(ptr);
        return;
    }
    while(ptr->link!=NULL && ptr->data!=specific)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    if (ptr==NULL)
    {
        return;
    }
    prev->link=ptr->link;
    free(ptr);
}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        printf("\nThe linked list is :\t");
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("%d\t\n",ptr->data);
    }
}