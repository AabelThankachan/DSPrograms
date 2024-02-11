// recursive traversal of binary tree using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *buildBinaryTree(int index)
{
    int value;
    struct node *root = NULL;

    printf("Enter the data for the node %d (or -1 for no data): ", index);
    scanf("%d", &value);

    if (value != -1)
    {
        root = createNode(value);

        printf("Enter the left child for node %d:\n", index);
        root->left = buildBinaryTree(2 * index + 1);

        printf("Enter the right child for node %d:\n", index);
        root->right = buildBinaryTree(2 * index + 2);
    }
    return root;
}

void displayPreorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayInorder(struct node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

void displayPostorder(struct node *root)
{
    if (root != NULL)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

void main()
{
    struct node *root = NULL;

    printf("Enter data for the binary tree:\n");
    root = buildBinaryTree(0);

    printf("\nBinary Tree (Pre-order traversal):\n");
    displayPreorder(root);

    printf("\nBinary Tree (In-order traversal):\n");
    displayInorder(root);

    printf("\nBinary Tree (Post-order traversal):\n");
    displayPostorder(root);
}
