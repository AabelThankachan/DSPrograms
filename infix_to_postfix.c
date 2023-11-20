// converting infix to postfix expression
#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    top--;
    return stack[top + 1];
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(const char infix[], char postfix[])
{
    int i = 0, j = 0;
    char token;
    while ((token = infix[i++]) != '\0')
    {
        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(token);
        }
        else if (token == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top >= 0 && stack[top] == '(')
            {
                pop(); // Discard the open parenthesis
            }
        }
        else
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while (top >= 0)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void main()
{
    char infix[100];
    char postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}
