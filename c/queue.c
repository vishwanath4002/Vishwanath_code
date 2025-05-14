#include <stdio.h>
int front=0,rear=0,lim;
int q[50];
void enqueue(int v)
{
	if (rear==lim)
	{
		printf("Queue full.\n");
	}
	else
	{
		q[rear]=v;
		rear++;
	}
}
void dequeue()
{
	if(rear==front)
	{
		printf("Queue empty.\n");
	}
	else
	{
		front++;
	}
}
void display()
{
	if(rear==front)
	{
		printf("Queue is empty.\n");
	}
	else
	{
		int i=front;
		while(i<rear)
		{
			printf("%d\t",q[i]);
			i++;
		}
	}
	printf("\n");
}
void main()
{
	int ch,v;
	printf("Enter the limit : ");
	scanf("%d",&lim);
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&v);
				enqueue(v);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printf("The queue is :\n");
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