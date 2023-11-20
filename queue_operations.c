#include <stdio.h>
#define MAX 10
int front = -1, rear = -1, arr[100];
void enqueue()
{
    int item;
    printf("Enter element to add:");
    scanf("%d", &item);
    if (rear == MAX - 1)
    {
        printf("Queue is full \n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            arr[++rear] = item;
        }
        else
        {
            arr[++rear] = item;
        }
    }
}

void dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        item = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("%d deleted \n", item);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Queue is: \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
}

void main()
{
    int item, choice;
    while (choice != 4)
    {
        printf("Enter operation: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter valid choice \n");
        }
    }
}
