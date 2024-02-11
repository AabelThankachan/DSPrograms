// linked list operations
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

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

void display_list()
{
    temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void add_afterdata()
{
    struct node *p;
    int after, num;
    temp = head;

    if (temp == NULL)
    {
        printf("List is empty \n");
    }

    else
    {
        printf("enter element after which you want to insert:");
        scanf("%d", &after);
        printf("enter element to insert:");
        scanf("%d", &num);

        while (temp != NULL && temp->data != after)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("%d not found in list \n", after);
        }

        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            p = temp->next;
            temp->next = newnode;
            newnode->data = num;
            newnode->next = p;
        }
    }
}

void add_beforedata()
{
    struct node *prev;
    int before, num;
    temp = head;

    printf("enter element before which you want to insert:");
    scanf("%d", &before);
    printf("enter element to insert:");
    scanf("%d", &num);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (head == NULL || temp->data == before)
    {
        newnode->next = head;
        head = newnode;
    }

    else
    {
        while (temp != NULL && temp->data != before)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("%d not found in list \n", before);
        }

        else
        {
            if (prev == NULL)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                prev->next = newnode;
                newnode->next = temp;
            }
        }
    }
}

void add_position()
{
    temp = head;
    int i = 1, pos, count = 0;
    printf("enter position at which you want to add:");
    scanf("%d", &pos);

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos > count + 1 || pos < 1)
    {
        printf("Invalid position \n");
    }

    else
    {
        temp = head;
        i = 1;

        if (pos == 1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter element:");
            scanf("%d", &newnode->data);
            newnode->next = head;
            head = newnode;
        }
        else
        {
            while (i < pos - 1 && temp != NULL)
            {
                temp = temp->next;
                i++;
            }
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("enter element:");
            scanf("%d", &newnode->data);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void delete_data()
{
    int num;
    printf("enter element to delete:");
    scanf("%d", &num);
    temp = head;
    struct node *prev = NULL;

    if (temp == NULL)
    {
        printf("List is empty \n");
        return;
    }

    if (temp->data == num)
    {
        head = temp->next;
        free(temp);
    }

    else
    {
        while (temp != NULL && temp->data != num)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("%d not found in list \n", num);
            return;
        }

        prev->next = temp->next;
        free(temp);
    }
}

void delete_position()
{
    int i = 1, pos, count = 0;
    struct node *prev = NULL;
    printf("enter position at which you want to delete:");
    scanf("%d", &pos);
    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos > count || pos < 1)
    {
        printf("Invalid position \n");
    }

    else
    {
        temp = head;
        i = 1;
        if (pos == 1)
        {
            head = head->next;
            free(temp);
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }

            if (temp == NULL || temp->next == NULL)
            {
                printf("Invalid position \n");
            }
            else
            {
                struct node *nextnode = temp->next->next;
                free(temp->next);
                temp->next = nextnode;
            }
        }
    }
}

void smallest_element()
{
    int min;
    temp = head->next;

    if (temp == NULL)
    {
        printf("List is empty \n");
        return;
    }

    min = temp->data;
    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("smallest element is %d \n", min);
}

void search()
{
    int num, count = 1;
    temp = head;
    printf("enter element to search for:");
    scanf("%d", &num);

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("%d at position %d \n", num, count);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("%d not found in list \n", num);
}

void main()
{
    int choice = 0;
    while (choice != 10)
    {
        printf("Enter choice: \n1.Create list \n2.Insert node after data \n3.Insert node before data \n4.Insert node at a position \n5.Delete value \n6.Delete node at a position \n7.Smallest element \n8.Search element \n9.Display \n10.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_list();
            break;

        case 2:
            add_afterdata();
            break;

        case 3:
            add_beforedata();
            break;

        case 4:
            add_position();
            break;

        case 5:
            delete_data();
            break;

        case 6:
            delete_position();
            break;

        case 7:
            smallest_element();
            break;

        case 8:
            search();
            break;

        case 9:
            display_list();
            break;

        case 10:
            break;

        default:
            printf("Invalid choice \n");
        }
    }
}