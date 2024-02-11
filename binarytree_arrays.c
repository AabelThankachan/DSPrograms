// binary tree operations using arrays
#include <stdio.h>
#define MAX_SIZE 100
void insertNode(int array[], int data)
{
    int i = 0;
    while (array[i] != 0)
    {
        i++;
    }
    array[i] = data;
}
void deleteNode(int array[], int key)
{
    int i = 0;
    while (array[i] != key)
    {
        i++;
    }
    if (array[2 * i + 1] == 0 && array[2 * i + 2] == 0)
    {
        array[i] = 0;
    }
    else if (array[2 * i + 1] == 0 || array[2 * i + 2] == 0)
    {
        if (array[2 * i + 1] != 0)
        {
            array[i] = array[2 * i + 1];
            array[2 * i + 1] = 0;
        }
        else
        {
            array[i] = array[2 * i + 2];
            array[2 * i + 2] = 0;
        }
    }
    else
    {
        int j = 2 * i + 2;
        while (array[2 * j + 1] != 0)
        {
            j = 2 * j + 1;
        }
        array[i] = array[j];
        array[j] = 0;
    }
}
void inorderTraversal(int array[], int index)
{
    if (index < MAX_SIZE && array[index] != 0)
    {
        inorderTraversal(array, 2 * index + 1);
        printf("%d ", array[index]);
        inorderTraversal(array, 2 * index + 2);
    }
}
void preorderTraversal(int array[], int index)
{
    if (index < MAX_SIZE && array[index] != 0)
    {
        printf("%d ", array[index]);
        preorderTraversal(array, 2 * index + 1);
        preorderTraversal(array, 2 * index + 2);
    }
}
void postorderTraversal(int array[], int index)
{
    if (index < MAX_SIZE && array[index] != 0)
    {
        postorderTraversal(array, 2 * index + 1);
        postorderTraversal(array, 2 * index + 2);
        printf("%d ", array[index]);
    }
}
void main()
{
    int array[MAX_SIZE] = {0};
    int choice, data, key;
    while (choice != 6)
    {
        printf("\nBinary Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(array, data);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteNode(array, key);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(array, 0);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorderTraversal(array, 0);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            postorderTraversal(array, 0);
            printf("\n");
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}