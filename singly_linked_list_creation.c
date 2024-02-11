#include <stdio.h>
#include <stdlib.h>

void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 1, count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("enter choice: 1 to add, 0 to stop:");
        scanf("%d", &choice);
    }

    printf("list is: \n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nThere are %d nodes", count);
}
