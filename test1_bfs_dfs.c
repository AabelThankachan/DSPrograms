#include <stdio.h>
#include <conio.h>
#define MAX 6

void bfs(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front = -1;
    for (int k = 0; k < MAX; k++)
    {
        visited[k] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) // queue is empty
    {
        start = queue[front++];
        printf("%d ", start);
        for (int i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int adj[][MAX], int visited[], int start)
{
    int stack[MAX], top = -1;
    for (int k = 0; k < MAX; k++)
    {
        visited[k] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) // stack is empty
    {
        start = stack[top--];
        printf("%d ", start);
        for (int i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

void main()
{
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int choice, start;
    while (choice != 4)
    {
        printf("Enter choice: \n1. Enter values \n2.BFS Traversal \n3.DFS Traversal \n4.Exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter adjacency matrix:\n");
            for (int i = 0; i < MAX; i++)
            {
                for (int j = 0; j < MAX; j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            break;

        case 2:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &start);
            printf("BFS Traversal...\n");
            bfs(adj, visited, start);
            printf("\n");
            break;

        case 3:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &start);
            printf("DFS Traversal...\n");
            dfs(adj, visited, start);
            printf("\n");
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice \n");
        }
    }
}