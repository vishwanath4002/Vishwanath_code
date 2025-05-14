#include <stdio.h>
int top=-1,max;
int s[50];
void push(int v)
{
	if(top==max-1)
	{
		printf("Stack overflow.\n");
	}
	else
	{
		top++;
		s[top]=v;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack underflow.\n");
	}
	else
	{
		top--;
	}
}
void display()
{
	int i=top;
	if (top==-1)
	{
		printf("Stack underflow.\n");
	}
	else
	{
		while(i>=0)
		{
			printf("\t%d",s[i]);
			i--;
		}
		printf("\n");
	}
}
void main()
{
	int ch,v;
	printf("Enter the limit : ");
	scanf("%d",&max);
	do
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be pushed : ");
				scanf("%d",&v);
				push(v);
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("The stack is : ");
				display();
				break;				
			case 4:
				break;
			default:
				printf("Invalid entry.");
		}
		printf("\n");
	}while(ch!=4);
}