#include <stdio.h>
int front = -1,rear = -1;
int size;
int q[15];

int isfull()
{
    return((front == rear+1)||(front==0 && rear==size-1));
}

int isempty()
{
    return(front == -1);
}

void enqueue(int e)
{
    if(isfull())
    {
        printf("\nQueue full.\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear = (rear+1)%size;
        q[rear] = e;
        printf("\nElement enqueued.\n");
    }
}

void dequeue()
{
    if(isempty())
    {
        printf("\nQueue empty.\n");
    }
    else
    {
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }
        printf("\nElement dequeued.\n");
    }
    
}

void display()
{
    if(isempty())
    {
        printf("\nQueue empty.\n");
    }
    else
    {
        int i;
        printf("The queue is : ");
        for(i = front ; i!= rear ; i = (i+1)%size)
        {
            printf("%d\t",q[i]);
        }
        printf("%d",q[i]);
    }
}

void main()
{
    int ch,e;
    printf("Enter the size of circular queue : ");
    scanf("%d",&size);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element to be equeued : ");
                scanf("%d",&e);
                enqueue(e);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
            case 4:
                break;
            default:
                printf("\nInvalid entry. Please try again.");
        }
    } while (ch!=4);
}