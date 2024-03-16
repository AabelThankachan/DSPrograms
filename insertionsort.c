// insertion sort
#include <stdio.h>
void read_array(int arr[], int n)
{
    int i;
    printf("enter the array elements: \n");
    for (i = 0; i < n; i++)
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
void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void main()
{
    int n, arr[20];
    printf("enter size of array: ");
    scanf("%d", &n);
    read_array(arr, n);
    insertion_sort(arr, n);
    display_array(arr, n);
}