// traversal of binary tree using array
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

void buildBinaryTree(int tree[], int index, int size)
{
    int value;
    printf("Enter the data for node %d (or enter -1 for no data): ", index);
    scanf("%d", &value);

    if (value == -1 || index >= size)
    {
        tree[index] = INT_MIN; // Using INT_MIN to represent an empty node
        return;
    }

    tree[index] = value;
    printf("Enter the left child for node %d:\n", index);
    buildBinaryTree(tree, 2 * index + 1, size);
    printf("Enter the right child for node %d:\n", index);
    buildBinaryTree(tree, 2 * index + 2, size);
}

void display_preorder_value(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        printf("%d\t", tree[index]);
        display_preorder_value(tree, 2 * index + 1, size);
        display_preorder_value(tree, 2 * index + 2, size);
    }
}

void display_preorder_index(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        printf("%d\t", index);
        display_preorder_index(tree, 2 * index + 1, size);
        display_preorder_index(tree, 2 * index + 2, size);
    }
}

void display_inorder_value(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        display_inorder_value(tree, 2 * index + 1, size);
        printf("%d\t", tree[index]);
        display_inorder_value(tree, 2 * index + 2, size);
    }
}

void display_inorder_index(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        display_inorder_index(tree, 2 * index + 1, size);
        printf("%d\t", index);
        display_inorder_index(tree, 2 * index + 2, size);
    }
}

void display_postorder_value(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        display_postorder_value(tree, 2 * index + 1, size);
        display_postorder_value(tree, 2 * index + 2, size);
        printf("%d\t", tree[index]);
    }
}

void display_postorder_index(int tree[], int index, int size)
{
    if (index < size && tree[index] != INT_MIN)
    {
        display_postorder_index(tree, 2 * index + 1, size);
        display_postorder_index(tree, 2 * index + 2, size);
        printf("%d\t", index);
    }
}

void main()
{
    int tree[MAX_SIZE];
    int size;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &size);

    // Build the binary tree
    buildBinaryTree(tree, 0, size);

    // Display the binary tree using pre-order traversal
    printf("\nBinary Tree (Pre-order traversal):\n");
    printf("Value:\t");
    display_preorder_value(tree, 0, size);
    printf("\nIndex:\t");
    display_preorder_index(tree, 0, size);

    printf("\nBinary Tree (In-order traversal):\n");
    printf("Value:\t");
    display_inorder_value(tree, 0, size);
    printf("\nIndex:\t");
    display_inorder_index(tree, 0, size);

    printf("\nBinary Tree (Post-order traversal):\n");
    printf("Value:\t");
    display_postorder_value(tree, 0, size);
    printf("\nIndex:\t");
    display_postorder_index(tree, 0, size);
}
