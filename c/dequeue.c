#include <stdio.h>
int front=-1,rear=-1;
int size;
int q[15];

int isfull()
{
    return((front==rear+1)||(front==0&&rear==size-1));
}

int isempty()
{
    return(front==-1);
}

void enqueuefromrear(int e)
{
    if(isfull())
    {
        printf("\nQueue full.\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        q[rear]=e;
        printf("\nElement enqueued.\n");
    }
}
void enqueuefromfront(int e)
{
	if(isfull())
    {
        printf("\nQueue full.\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        else if(front==0)
        {
        	front=size-1;
		}
		else
		{
			front --;
		}
		q[front]=e;
   	    printf("\nElement enqueued.\n");
    }
}
void dequeuefromfront()
{
    if(isempty())
    {
        printf("\nQueue empty.\n");
    }
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        printf("\nElement dequeued.\n");
    }
}

void dequeuefromrear()
{
    if(isempty())
    {
        printf("\nQueue empty.\n");
    }
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
        	rear--;
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
        int i=0;
        printf("\nFront = %d",front);
        printf("\nRear = %d\n",rear);
        printf("\nQueue is : ");
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d\t",q[i]);
        }
        printf("%d",q[i]);

    }
}

void main()
{
    int ch1,ch2,e;

    do
    {
        printf("Enter the size of double ended queue : ");
    	scanf("%d",&size);
    	printf("1.Input Restricted\n2.Output restricted\n3.Exit\nEnter your choice : ");
    	scanf("%d",&ch1);
    	switch(ch1)
    	{
    		case 1:
    			do
    			{
					printf("\n1.Enqueue from rear\n2.Dequeue from rear\n3.Dequeue from front\n4.Display\n5.Exit\nEnter your choice : ");
					scanf("%d",&ch2);
					switch(ch2)
					{
						case 1:
						    printf("\nEnter the element to be equeued : ");
						    scanf("%d",&e);
						    enqueuefromrear(e);
						    break;
						case 2:
						    dequeuefromrear();
						    break;
						case 3:
							dequeuefromfront();
							break;
						case 4:
							display();
							break;
						case 5:
							break;
						default:
							printf("\nInvalid Entry.");
					}
				}while(ch2!=5);
				break;
			
			case 2:
				do
				{
					printf("\n1.Enqueue from front\n2.Enqueue from rear\n3.Dequeue from front\n4.Display\n5.Exit\nEnter your choice : ");
					scanf("%d",&ch2);
					switch(ch2)
					{
						case 1:
							printf("\nEnter the element to be equeued : ");
							scanf("%d",&e);
				            enqueuefromfront(e);
				            break;
				        case 2:
				 		    printf("\nEnter the element to be equeued : ");
							scanf("%d",&e);
							enqueuefromrear(e);
							break;
		        		case 3:
		        			dequeuefromfront();
		        			break;
		        		case 4:
		        			display();
		        			break;
		        		case 5:
		        			break;
		        		default:
		        			printf("\nInvalid entry.");
					}
				}while(ch2!=5);
				break;
			
			case 3:
				break;

			default:
				printf("\nInvalid entry.");
    	}
    }while(ch1!=3);
}
