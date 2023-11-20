// searching,adding,removing,swapping,replacing elements in array
#include <stdio.h>

// searching element
long int Array_search(int arr[], int n)
{
    int i, num, flag = 0;
    printf("enter element to search:");
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
        printf("%d is at position %d", num, i + 1);
    else
        printf("%d not in array", num);
}

// adding element
long int Array_add(int arr[], int n)
{
    int i, add;
    printf("enter element to be added:");
    scanf("%d", &add);
    arr[n] = add;
    printf("the new array is: \n");
    for (i = 0; i <= n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

// removing element
long int Array_remove(int arr[], int n)
{
    int i, j, x, flag = 0;
    printf("enter position of element you want to delete:\n ");
    scanf("%d", &x);
    if (x >= n + 1)
    {
        printf("cannot delete element");
    }
    else
    {
        for (i = x - 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("the new array is: \n");
        for (i = 0; i < n - 1; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
}

// swapping element
long int Array_swap(int arr[], int n)
{
    int i, x, y, temp;
    printf("enter position of elements to be swapped: \n");
    scanf("%d %d", &x, &y);
    if (x > n || y > n)
        printf("enter valid positions");
    else
    {
        temp = arr[x - 1];
        arr[x - 1] = arr[y - 1];
        arr[y - 1] = temp;
        printf("new array is: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
}

// replacing element
long int Array_replace(int arr[], int n)
{
    int i, x, y, flag = 0;
    printf("enter number you want to replace:");
    scanf("%d", &x);
    printf("enter new number:");
    scanf("%d", &y);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            arr[i] = y;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("the new array is: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
    else
        printf("cannot replace element");
}

void main()
{
    int i, n, op;
    printf("enter how many elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("enter the array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter operation: \n 1.Search element \n 2.Add element \n 3.Remove element \n 4.Swap element \n 5.Replace element \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        Array_search(arr, n);
        break;
    case 2:
        Array_add(arr, n);
        break;
    case 3:
        Array_remove(arr, n);
        break;
    case 4:
        Array_swap(arr, n);
        break;
    case 5:
        Array_replace(arr, n);
        break;
    default:
        printf("invalid operation");
    }
}