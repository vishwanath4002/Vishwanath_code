#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coef;
	int exp;
	struct node *link;
};
typedef struct node Node;
Node *result=NULL;
Node *poly1=NULL,*poly2=NULL;

void insert(Node **poly,int coef, int exp);
void print(Node *poly);
void add(Node *poly1,Node *poly2);
void multiply(Node *poly1, Node *poly2);

void main()
{
	int num,coef,exp,choice;
	do
	{
		printf("\n1.Polynomial Addition\n2.Polynomial Multiplicaion\n3.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		if (choice!=3)
		{
			printf("Enter the number of elements in polynomial 1 : ");
			scanf("%d",&num);
			for(int i=0;i<num;i++)
			{
				printf("\nElement %d:\n",i+1);
				printf("Enter the coefficient : ");
				scanf("%d",&coef);
				printf("Enter the power of x : ");
				scanf("%d",&exp);
				insert(&poly1,coef,exp);
			}
			printf("Enter the number of elements in polynomial 2 : ");
			scanf("%d",&num);
			for(int i=0;i<num;i++)
			{
				printf("\nElement %d:\n",i+1);
				printf("Enter the coefficient : ");
				scanf("%d",&coef);
				printf("Enter the power of x : ");
				scanf("%d",&exp);
				insert(&poly2,coef,exp);
			}
			printf("The polynomials are : \n");
			print(poly1);
			print(poly2);
		}
		switch(choice)
		{
			case 1:
				add(poly1,poly2);
				printf("The sum is :\n");
				print(result);
				break;
			
			case 2:
				multiply(poly1,poly2);
				printf("The product is :\n");
				//print(result);
				break;
				
			case 3:
				break;
			
			default:
				printf("Invalid entry.");
			
		}
	}while(choice!=3);
}

void insert(Node **poly,int coef, int exp)
{
	Node *temp=malloc(sizeof(Node));
	temp->coef=coef;
	temp->exp=exp;
	temp->link=NULL;
	if(*poly==NULL)
	{
		*poly=temp;
		return;
	}
	Node *ptr=*poly;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
}

void print(Node *poly)
{
	if (poly==NULL)
	{
		printf("No elements in polynomial.");
		return;
	}
	Node *ptr=poly;
	while(ptr->link!=NULL)
	{
		printf("%dx^%d",ptr->coef,ptr->exp);
		if(ptr->link!=NULL)
		{
			printf("+");
		}
		ptr=ptr->link;
	}
	printf("%dx^%d\n",ptr->coef,ptr->exp);
}

void add(Node *poly1,Node *poly2)
{
	while(poly1->link!=NULL && poly2->link!=NULL)
	{
		if(poly1->exp==poly2->exp)
		{
			insert(&result,poly1->coef+poly2->coef,poly1->exp);
			poly1=poly1->link;
			poly2=poly2->link;
		}
		else if(poly1->exp>poly2->exp)
		{
			insert(&result,poly1->coef,poly1->exp);
			poly1=poly1->link;
		}
		else 
		{
			insert(&result,poly2->coef,poly2->exp);
			poly2=poly2->link;
		}
	}
	while(poly1!=NULL)
	{
		insert(&result,poly1->coef,poly1->exp);
		poly1=poly1->link;
	}
	while(poly2!=NULL)
	{
		insert(&result,poly2->coef,poly2->exp);
		poly2=poly2->link;
	}
}

void multiply(Node *poly1, Node *poly2)
{
	Node *ptr1,*ptr2;
	ptr1=poly1;
	ptr2=poly2;
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			int flag=0;
			Node *temp=malloc(sizeof(Node));
			int coef=ptr1->coef*ptr2->coef;
			int exp=ptr1->exp*ptr2->exp;
			printf("%dx^%d+",coef,exp);
			if (result==NULL)
			{
				insert(&result,coef,exp);
			}
			else
			{
				while(result!=NULL)
				{
					if(result->exp==exp)
					{
						result->coef+=coef;
						flag=1;
						break;
					}
					result=result->link;
				}
				if(flag==0)
				{
					insert(&result,coef,exp);
				}
			}
			free(temp);
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
}





















