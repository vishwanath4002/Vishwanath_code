#include <stdio.h>

int g[20][20];
int queue[10];
int stack[10];
int visited[10];

int n;              //number of vertices
int c=0;
int front =-1, rear=-1, top=-1;

void enqueue(int v)
{
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear]=v;
}

int dequeue()
{
    int item;
    if (front == rear == -1)
    {
        printf("\nBFS displayed.");
        return;
    }
    else if (front == rear)
    {
        item = queue[front];
        front = rear = -1;
    }
    else
    {
        item = queue[front];
        front++;
    }
    return item;
}

void push(int v)
{
    top++;
    stack[top]=v;
}

int pop()
{
    int item;
    if (top == -1)
    {
        printf("\nDFS Displayed.");
        return;
    }
    else
    {
        item = stack[top];
        top--;
    }
    return item;
}

void BFS(int s)
{
    enqueue(s);
    for(int i=0;i<n;i++)
    {
        if(g[s][i] == 1 && g[s][i]!=s)
        {
            enqueue(g[s][i]);
        }
    }
}

void main()
{
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    
    //read matrix
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            do
            {
                scanf("%c",&c);
                printf("\nIs vertex %d connected to vertex %d (y/n) : ",i+1,j+1);
                scanf("%c",&c);
                if (c == 'y')
                {
                    g[i][j] = 1;
                }
                else if(c == 'n')
                {
                    g[i][j] = 0;
                }
                else
                {
                    printf("\nInvalid entry.\n");
                }
            }while (c!='y' || c!='n');
        }
    }

    //Display
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }

    //searching
    int ch,sv;
    printf("\n1.BFS\n2.DFS\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter the starting vertex : ");
            scanf("%d",&sv);
            printf("BFS traversal starting from %d :",sv);
            BFS(sv-1);
    }
    

}
