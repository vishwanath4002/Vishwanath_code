#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *link;
};

struct node *head, *temp, *head1, *head2, *head3, *head4, *ptr1, *ptr2, *ptr3, *ptr4, *p, *temp2, *ptr;
int m,n;

void create(int c, int e)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=c;
    temp->exp=e;
    temp->link=NULL;
}

struct node *insert()
{
    if(head==NULL)
    {
        head=temp;
        ptr=head;
    }
    else
    {
        ptr->link=temp;
        ptr=ptr->link;
    }
    return head;
}

void display(struct node *head)
{
    ptr=head;
    while(ptr->link!=NULL)
    {
        if(ptr->exp==0)
        {
            printf("%d+",ptr->coef);
        }
        else
        {
            printf("%dx^%d+", ptr->coef, ptr->exp);
        }
        ptr=ptr->link;
    }
    if(ptr->exp==0)
    {
        printf("%d\n",ptr->coef);
        return;
    }
    printf("%dx^%d\n",ptr->coef, ptr->exp);
}

struct node *Add(struct node *ptr1, struct node *ptr2)
{
    int sum=0;
    head=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if((ptr1->exp)>(ptr2->exp))
        {
            create(ptr1->coef,ptr1->exp);
            head=insert();
            ptr1=ptr1->link;
        }
        else if((ptr1->exp)<(ptr2->exp))
        {
            create(ptr2->coef,ptr2->exp);
            head=insert();
            ptr2=ptr2->link;
        }
        else
        {
            sum=ptr1->coef+ptr2->coef;
            create(sum, ptr1->exp);
            head=insert();
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
    }
   
    while(ptr1!=NULL)
    {
        create(ptr1->coef,ptr1->exp);
        head=insert();
        ptr1=ptr1->link;
    }
   
    while(ptr2!=NULL)
    {
        create(ptr2->coef,ptr2->exp);
        head=insert();
        ptr2=ptr2->link;
    }
   
    return head;
}

struct node *Multiply(struct node *ptr1, struct node *ptr2)
{
    int p,s;
    head=NULL;
    temp2=ptr2;
    for(int i=0;i<m;i++)
    {
        ptr2=temp2;
        for(int j=0;j<n;j++)
        {
           p=ptr1->coef*ptr2->coef;
           s=ptr1->exp+ptr2->exp;
           create(p,s);
           head=insert();
           ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
   
    return head;
}

void deletem(int c, struct node *h)
{
    p=h;
   
    while(p->link->coef!=c)
    {
        p=p->link;
    }
    p->link=p->link->link;
}


void main()
{  
    int choice;
    do
    {
        head=NULL;
        head1=NULL;
        head2=NULL;
        head3=NULL;
        head4=NULL;
        printf("1.Addition\n2.Multiplication\n3.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        int c,e;
        if(choice==1 || choice==2)
        {
            printf("\nEnter the no. of terms in the first polynomial : ");
            scanf("%d",&m);
            for(int i=0;i<m;i++)
            {
                printf("Enter the coefficient and exponent of %d term : ",(i+1));
                scanf("%d%d",&c,&e);
                create(c,e);
                head1=insert();
            }
            head=NULL;
            printf("\nEnter the no. of terms in the second polynomial : ");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                printf("Enter the coefficient and exponent of %d term : ",(i+1));
                scanf("%d%d",&c,&e);
                create(c,e);
                head2=insert();
            }
            printf("\nFirst Polynomial : ");
            display(head1);
            printf("\nSecond Polynomial : ");
            display(head2);
        }

        switch (choice)
        {
            case 1:
                head=NULL;
                head3=Add(head1,head2);
                printf("\nSum:");
                display(head3);
                break;
            
            case 2:
                head4=Multiply(head1,head2);
                ptr4=head4;
                ptr3=ptr4->link;
            
                while(ptr4->link!=NULL)
                {
                    while(ptr3!=NULL)
                    {
                        if(ptr4->exp==ptr3->exp)
                        {
                            ptr4->coef=ptr4->coef+ptr3->coef;
                            temp2=ptr3->link;
                            deletem(ptr3->coef,head4);
                            ptr3=temp2;
                        }
                        else
                        {
                            ptr3=ptr3->link;
                        }
                    }
                    ptr4=ptr4->link;
                    ptr3=ptr4->link;
                }
                printf("\nProduct=");
                display(head4);
                break;
            
            case 3:
                break;

            default:
                printf("Invalid entry.");
                break;
        }
    } while (choice!=3);
}

