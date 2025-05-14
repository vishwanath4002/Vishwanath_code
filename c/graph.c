#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int startVertex) {
    struct Node* queue[MAX];
    int front = -1, rear = -1;
    queue[++rear] = graph->adjLists[startVertex];
    graph->visited[startVertex] = 1;

    while (front != rear) {
        struct Node* temp = queue[++front];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                printf("Visited %d \n", adjVertex);
                queue[++rear] = graph->adjLists[adjVertex];
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void displayAdjacencyList(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void displayAdjacencyMatrix(struct Graph* graph) {
    int adjMatrix[MAX][MAX];

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        while (temp) {
            adjMatrix[v][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, vertices, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    while (1)
    {
        printf("\n1. Add edge\n2. Depth First Search (DFS)\n3. Breadth First Search (BFS)\n4. Display Adjacency List\n5. Display Adjacency Matrix\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter source and destination vertex: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS Traversal: \n");
                DFS(graph, startVertex);
                break;
            case 3:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                printf("BFS Traversal: \n");
                BFS(graph, startVertex);
                break;
            case 4:
                displayAdjacencyList(graph);
                break;
            case 5:
                displayAdjacencyMatrix(graph);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}