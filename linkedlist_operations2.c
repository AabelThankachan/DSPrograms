// reversing and sorting linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *head, *temp;

void create_list()
{
    head = 0;
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }

        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void reverse_list()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot reverse.\n");
        return;
    }
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort_list()
{
    struct node *current, *index;
    int temp;

    if (head == NULL)
    {
        printf("List is empty. Nothing to sort.\n");
        return;
    }

    for (current = head; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                // Swap data values
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("Enter choice: \n1.Create list \n2.Reverse list \n3.Sort list \n4.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_list();
            printf("List is: \n");
            display();
            break;
        case 2:
            printf("Reversed list is: \n");
            reverse_list();
            display();
            break;
        case 3:
            printf("Sorted list is: \n");
            sort_list();
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice \n");
        }
    }
}