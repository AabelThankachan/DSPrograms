// all searching techniques
#include <stdio.h>
long int linear_search(int arr[], int n)
{
    int i, num, flag = 0;
    printf("enter element to search: ");
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("%d found at position %d \n", num, i + 1);
    else
        printf("%d not found in array \n", num);
}
long int binary_search(int arr[], int n)
{
    int num, flag = 0, low = 0, high = n - 1, mid = (low + high) / 2;
    printf("enter the number to search:");
    scanf("%d", &num);
    while (high >= low)
    {
        if (arr[mid] == num)
        {
            flag = 1;
            break;
        }
        else if (num < arr[mid])
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    if (flag == 1)
        printf("%d is at position %d \n", num, mid + 1);
    else
        printf("%d is not in array \n", num);
}
void read_array(int arr[], int n)
{
    int i;
    printf("enter array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void main()
{
    int n;
    printf("enter size of array: ");
    scanf("%d", &n);
    int arr[n], choice;
    read_array(arr, n);
    while (choice != 3)
    {
        printf("enter choice:\n1. Linear search \n2. Binary search \n3. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Linear search...\n");
            linear_search(arr, n);
            break;
        case 2:
            printf("Binary search...\n");
            binary_search(arr, n);
            break;
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice \n");
        }
    }
}
