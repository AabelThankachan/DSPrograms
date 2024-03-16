#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
#define MAX_VERTICES 100
int visited[MAX_VERTICES];
void BFS(int adjacencyMatrix1[MAX_SIZE][MAX_SIZE], int vertices, int startVertex)
{
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    bool visited[MAX_SIZE] = {false};

    queue[++rear] = startVertex;
    visited[startVertex] = true;

    while (front != rear)
    {
        int currentVertex = queue[++front];

        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (adjacencyMatrix1[currentVertex][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}
void dfs(int start, int adjacencyMatrix2[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < numVertices; i++)
    {
        if (adjacencyMatrix2[start][i] && !visited[i])
        {
            dfs(i, adjacencyMatrix2, numVertices);
        }
    }
}
void main()
{
    int adjacencyMatrix1[MAX_SIZE][MAX_SIZE];
    int vertices, startVertex;
    printf("BFS Traversal...\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjacencyMatrix1[i][j]);
        }
    }
    printf("BFS traversal: ");
    BFS(adjacencyMatrix1, vertices, startVertex);
    printf("\n");
    printf("DFS Traversal...\n");
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    int adjacencyMatrix2[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjacencyMatrix2[i][j]);
        }
    }
    printf("DFS traversal: ");
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjacencyMatrix2, numVertices);
        }
    }
}
