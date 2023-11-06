#include <stdio.h>
int arr1[100], arr2[100], top1 = -1, top2 = -1;

void push1(int item)
{
    top1++;
    arr1[top1] = item;
}

void push2(int item)
{
    top2++;
    arr2[top2] = item;
}

void pop1()
{
    if (top1 == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        top1--;
    }
}

void display()
{
    if (top1 == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Sorted Stack is: \n");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d ", arr1[i]);
        }
    }
}

void main()
{
    int item, choice = 0;
    while (choice != 2)
    {
        printf("Type 1 to enter an element and 2 to exit \n");
        scanf("%d", &choice);
        if (choice == 2)
        {
            break;
        }
        else if (choice == 1)
        {
            printf("Enter an element: ");
            scanf("%d", &item);
            if (top1 == -1)
            {
                push1(item);
            }
            else
            {
                while (item < arr1[top1])
                {
                    push2(arr1[top1]);
                    pop1();
                }
                push1(item);
                while (top2 >= 0)
                {
                    push1(arr2[top2]);
                    top2--;
                }
            }
        }
        else
        {
            printf("Enter a valid option \n");
        }
    }
    display();
}
