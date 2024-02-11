// non-recursive traversal of binary tree using linked list
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

void inorder(struct node *root)
{
    struct node *stack[100];
    int top = -1;

    while (root != NULL || top != -1)
    {
        while (root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        printf("%d ", root->data);

        root = root->right;
    }
}

void preorder(struct node *root)
{
    struct node *stack[100];
    int top = -1;

    while (root != NULL || top != -1)
    {
        while (root != NULL)
        {
            printf("%d ", root->data);
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];
        root = root->right;
    }
}

void postorder(struct node *root)
{
    struct node *stack1[100];
    struct node *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        root = stack1[top1--];
        stack2[++top2] = root;

        if (root->left != NULL)
            stack1[++top1] = root->left;

        if (root->right != NULL)
            stack1[++top1] = root->right;
    }

    while (top2 != -1)
    {
        printf("%d ", stack2[top2--]->data);
    }
}

struct node *buildBinaryTree(int index)
{
    int value;
    struct node *root = NULL;

    printf("Enter the data for node %d (or -1 for no data): ", index);
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

void main()
{
    struct node *root = NULL;

    printf("Enter data for the binary tree:\n");
    root = buildBinaryTree(0);

    printf("\nIn-order traversal: \n");
    inorder(root);

    printf("\nPre-order traversal: \n");
    preorder(root);

    printf("\nPost-order traversal: \n");
    postorder(root);
}
