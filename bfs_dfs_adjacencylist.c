#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge1(struct Node **adjList1, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = adjList1[src];
    adjList1[src] = newNode;
}
void addEdge2(struct Node *adjList2[], int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = adjList2[src];
    adjList2[src] = newNode;
}

void BFS(struct Node **adjList1, int startVertex, int numVertices1)
{
    struct Node *queue = NULL;
    int *visited = malloc(numVertices1 * sizeof(int));
    for (int i = 0; i < numVertices1; i++)
    {
        visited[i] = 0;
    }
    struct Node *startNode = createNode(startVertex);
    visited[startVertex] = 1;
    queue = startNode;
    while (queue != NULL)
    {
        struct Node *currentVertex = queue;
        queue = queue->next;
        printf("%d ", currentVertex->vertex);
        struct Node *neighbor = adjList1[currentVertex->vertex];
        while (neighbor != NULL)
        {
            if (!visited[neighbor->vertex])
            {
                struct Node *newNeighbor = createNode(neighbor->vertex);
                visited[neighbor->vertex] = 1;
                if (queue == NULL)
                {
                    queue = newNeighbor;
                }
                else
                {
                    struct Node *temp = queue;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNeighbor;
                }
            }
            neighbor = neighbor->next;
        }
    }
}
void DFS(int v, bool visited[], struct Node *adjList2[])
{
    visited[v] = true;
    printf("%d ", v);

    struct Node *temp = adjList2[v];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
        {
            DFS(neighbor, visited, adjList2);
        }
        temp = temp->next;
    }
}
void DFSUtil(int numVertices2, struct Node *adjList2[])
{
    bool visited[MAX_VERTICES];
    for (int i = 0; i < numVertices2; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < numVertices2; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited, adjList2);
        }
    }
}
void main()
{
    int numVertices1 = 5;
    struct Node **adjList1 = malloc(numVertices1 * sizeof(struct Node *));
    for (int i = 0; i < numVertices1; i++)
    {
        adjList1[i] = NULL;
    }
    addEdge1(adjList1, 0, 1);
    addEdge1(adjList1, 0, 2);
    addEdge1(adjList1, 1, 3);
    addEdge1(adjList1, 1, 4);
    addEdge1(adjList1, 2, 4);
    printf("BFS traversal: ");
    BFS(adjList1, 0, numVertices1);
    printf("\n");
    int numVertices2 = 5;
    struct Node *adjList2[MAX_VERTICES];
    for (int i = 0; i < numVertices2; i++)
    {
        adjList2[i] = NULL;
    }
    addEdge2(adjList2, 0, 1);
    addEdge2(adjList2, 0, 2);
    addEdge2(adjList2, 1, 3);
    addEdge2(adjList2, 2, 4);
    printf("DFS traversal: ");
    DFSUtil(numVertices2, adjList2);
}
