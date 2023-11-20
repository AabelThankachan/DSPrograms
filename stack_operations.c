// push, pop, peek and display stack
#include <stdio.h>
int arr[100], top = -1;
void push(int n)
{
    if (top > n - 2)
    {
        printf("Stack is full \n");
    }
    else
    {
        int item;
        printf("Enter element to push: ");
        scanf("%d", &item);
        top++;
        arr[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        int item1;
        item1 = arr[top--];
        printf("%d popped \n", item1);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Topmost item is %d \n", arr[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Stack is \n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void main()
{
    int n;
    printf("Enter maximum elements in stack: ");
    scanf("%d", &n);
    int choice;
    while (choice != 5)
    {
        printf("Enter operation: \n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Enter valid choice \n");
        }
    }
}
