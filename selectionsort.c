// selection sort
#include <stdio.h>
void read_array(int arr[], int n)
{
    printf("enter elements in the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int n)
{
    printf("the sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void selection_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
void main()
{
    int n, arr[20];
    printf("enter size of array: ");
    scanf("%d", &n);
    read_array(arr, n);
    selection_sort(arr, n);
    display_array(arr, n);
}