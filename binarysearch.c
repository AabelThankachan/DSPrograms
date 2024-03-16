// binary search using functions
#include <stdio.h>
void read_array(int arr[], int n)
{
    int i;
    printf("enter elements in sorted order: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
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
        printf("%d is at position %d", num, mid + 1);
    else
        printf("%d is not in array", num);
}
void main()
{
    int n, arr[20];
    printf("enter the size of array:");
    scanf("%d", &n);
    read_array(arr, n);
    binary_search(arr, n);
}