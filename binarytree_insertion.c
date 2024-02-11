// inserting element into binary tree
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

struct node *insertElement(struct node *root, int data, int pos, int currentPos)
{
    if (root == NULL)
    {
        // If the tree is empty, create a new node and make it the root
        if (pos == currentPos)
        {
            return createNode(data);
        }
        return NULL;
    }

    // If the current position matches the desired position, insert the element
    if (pos == currentPos)
    {
        struct node *newNode = createNode(data);
        newNode->left = root;
        return newNode;
    }

    // Otherwise, recur down the tree
    root->left = insertElement(root->left, data, pos, 2 * currentPos + 1);
    root->right = insertElement(root->right, data, pos, 2 * currentPos + 2);

    // Return the unchanged node pointer
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void main()
{
    struct node *root = NULL;
    int n, element, pos;

    printf("Enter data for the binary tree:\n");
    root = buildBinaryTree(0);

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter the element and corresponding index:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        scanf("%d", &pos);
        root = insertElement(root, element, pos, 0);
    }

    printf("In-order traversal of the binary tree: \n");
    inorderTraversal(root);

    printf("\nPre-order traversal of the binary tree: \n");
    preorderTraversal(root);

    printf("\nPost-order traversal of the binary tree: \n");
    postorderTraversal(root);
}