// checking for palindrome string using linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list node
struct node
{
    char data;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node *newNode(char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to insert a new node at the end of the doubly linked list
void insert(struct node **head, char new_data)
{
    struct node *newnode = newNode(new_data);
    struct node *last = *head;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newnode;
    newnode->prev = last;
}

// Function to check if the string is a palindrome
int palindrome(struct node *head)
{
    struct node *start = head;
    struct node *end = head;

    // Move 'end' to the last node
    while (end->next != NULL)
    {
        end = end->next;
    }

    while (start != NULL && end != NULL)
    {
        if (start->data != end->data)
        {
            return 0;
        }

        // Move to the next nodes from both ends
        start = start->next;
        end = end->prev;
    }
    return 1;
}

void main()
{
    struct node *head = NULL;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        insert(&head, str[i]);
    }

    if (palindrome(head))
    {
        printf("Yes, it is a palindrome");
    }
    else
    {
        printf("No, it is not a palindrome");
    }
}