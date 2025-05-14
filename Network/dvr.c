#include <stdio.h>

#define MAX_NODES 10
#define INF 9999

typedef struct
{
    int distance[MAX_NODES];
    int nextHop[MAX_NODES];
} RoutingTable;

int main()
{
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    
    int costMatrix[MAX_NODES][MAX_NODES];
    RoutingTable table[MAX_NODES];
    
    printf("Enter the cost matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            scanf("%d", &costMatrix[i][j]);
            if (i == j)
            { 
            	costMatrix[i][j] = 0; // Distance to self is 0
            }
            table[i].distance[j] = costMatrix[i][j];
            table[i].nextHop[j] = (costMatrix[i][j] == INF) ? -1 : j;
        }
    }
    
    int updated;
    do
    {
        updated = 0;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                for (int k = 0; k < nodes; k++)
                {
                    if (table[i].distance[k] > costMatrix[i][j] + table[j].distance[k])
                    {
                        table[i].distance[k] = costMatrix[i][j] + table[j].distance[k];
                        table[i].nextHop[k] = j;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
    
    printf("\nRouting Tables:\n");
    for (int i = 0; i < nodes; i++)
    {
        printf("Router %d:\n", i);
        printf("Destination\tCost\tNext Hop\n");
        for (int j = 0; j < nodes; j++) 
        
            printf("%d\t\t%d\t%d\n", j, table[i].distance[j], table[i].nextHop[j]);
        }
        printf("\n");
    }
    return 0;
}

