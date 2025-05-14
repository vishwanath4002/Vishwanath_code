#include<stdio.h>
#define MAX 100

int visited[MAX];
int adjMatrix[MAX][MAX];

int numv, front=-1, rear=-1;
int queue[MAX],visitedbfs[MAX];

void creatematrix()
{
    for (int i=0;i<numv;i++)
    {
        for(int j=0;j<numv;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
}

void displaymatrix()
{
    for (int i=0;i<numv;i++)
    {
        for(int j=0;j<numv;j++)
        {
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void addEdge(int u, int v)
{
    adjMatrix[u][v]=1;
    printf("Edge added.\n");
}

void bfs(int v)
{
    for (int i = 0; i < numv; i++)
        if (adjMatrix[v][i] && !visitedbfs[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visitedbfs[queue[front]] = 1;
        printf("%d ",queue[front]);
        bfs(queue[front++]);
    }
}

void dfs(int start)
{
    visited[start]=1;
    printf("%d ",start);

    for(int i=0;i<numv;i++)
    {
        if(adjMatrix[start][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void main()
{
    printf("Enter the number of vertices : ");
    scanf("%d",&numv);
    creatematrix();
    int ch;
    do
    {
        printf("1.Add edge\n2.Display adjacency matrix\n3.Dfs\n4.Bfs\n5.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        int u,v,s;
        switch(ch)
        {
            case 1:
                printf("Enter the vertices between which the edge should be added : ");
                scanf("%d%d",&u,&v);
                addEdge(u,v);
                break;
            
            case 2:
                displaymatrix();
                break;
            
            case 3:
                printf("Enter the starting vertex for dfs traversal : ");
                scanf("%d",&s);
                dfs(s);
                break;
            
            case 4:
                printf("Enter the starting vertex for bfs traversal : ");
                scanf("%d",&s);
                bfs(s);
                break;
            
            case 5:
                break;

            default:
                printf("Invalid entry.\n");
        }
        printf("\n");
    } while (ch!=5);
}