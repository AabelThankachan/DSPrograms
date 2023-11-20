#include <stdio.h>
#include <math.h>
#define MAX 10
int top = -1, stack[100];
char postfix[100];

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack is full");
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Empty stack \n");
    }
    int val = stack[top--];
    return val;
}

int evaluate()
{
    int i;
    char symbol;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
        {
            push(symbol - '0');
        }
        else
        {
            int a = pop();
            int b = pop();
            switch (symbol)
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop();
}

void main()
{
    printf("enter the postfix expression: ");
    scanf("%s", postfix);
    printf("The result is %d", evaluate());
}