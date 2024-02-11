// polynomial addition using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *temp, *temp1, *temp2;

void create_polynomial(struct node **head)
{
    if (*head != NULL)
    {
        printf("Polynomial already exists. Cannot reassign values.\n");
        return;
    }

    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    while (n)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &temp->coeff);
        printf("Enter the exponent: ");
        scanf("%d", &temp->exp);
        temp->next = NULL;

        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            struct node *current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
        n--;
    }
}

void display_polynomial(struct node *head)
{
    temp = head;
    printf("Polynomial is: ");
    while (temp != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

void add_polynomial(struct node *head1, struct node *head2)
{
    temp1 = head1;
    temp2 = head2;
    struct node *newNode = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            if (newNode == NULL)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->coeff = temp1->coeff + temp2->coeff;
                newNode->exp = temp1->exp;
                newNode->next = NULL;
            }
            else
            {
                struct node *last = newNode;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = (struct node *)malloc(sizeof(struct node));
                last->next->coeff = temp1->coeff + temp2->coeff;
                last->next->exp = temp1->exp;
                last->next->next = NULL;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            if (newNode == NULL)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->coeff = temp1->coeff;
                newNode->exp = temp1->exp;
                newNode->next = NULL;
            }
            else
            {
                struct node *last = newNode;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = (struct node *)malloc(sizeof(struct node));
                last->next->coeff = temp1->coeff;
                last->next->exp = temp1->exp;
                last->next->next = NULL;
            }
            temp1 = temp1->next;
        }
        else
        {
            if (newNode == NULL)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->coeff = temp2->coeff;
                newNode->exp = temp2->exp;
                newNode->next = NULL;
            }
            else
            {
                struct node *last = newNode;
                while (last->next != NULL)
                {
                    last = last->next;
                }
                last->next = (struct node *)malloc(sizeof(struct node));
                last->next->coeff = temp2->coeff;
                last->next->exp = temp2->exp;
                last->next->next = NULL;
            }
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        if (newNode == NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->coeff = temp1->coeff;
            newNode->exp = temp1->exp;
            newNode->next = NULL;
        }
        else
        {
            struct node *last = newNode;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = (struct node *)malloc(sizeof(struct node));
            last->next->coeff = temp1->coeff;
            last->next->exp = temp1->exp;
            last->next->next = NULL;
        }
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        if (newNode == NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->coeff = temp2->coeff;
            newNode->exp = temp2->exp;
            newNode->next = NULL;
        }
        else
        {
            struct node *last = newNode;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = (struct node *)malloc(sizeof(struct node));
            last->next->coeff = temp2->coeff;
            last->next->exp = temp2->exp;
            last->next->next = NULL;
        }
        temp2 = temp2->next;
    }

    display_polynomial(newNode);
}

void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int choice;

    while (choice != 6)
    {
        printf("\nEnter choice: \n");
        printf("1. Create First Polynomial.\n");
        printf("2. Create Second Polynomial.\n");
        printf("3. Display First Polynomial.\n");
        printf("4. Display Second Polynomial.\n");
        printf("5. Add Two Polynomials.\n");
        printf("6. Exit.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_polynomial(&head1);
            break;
        case 2:
            create_polynomial(&head2);
            break;
        case 3:
            display_polynomial(head1);
            break;
        case 4:
            display_polynomial(head2);
            break;
        case 5:
            add_polynomial(head1, head2);
            break;
        case 6:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}