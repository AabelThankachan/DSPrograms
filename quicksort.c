// quick sort
#include <stdio.h>
void read_array(int arr[], int n)
{
    printf("enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int n)
{
    printf("sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int partition(int arr[], int lb, int ub)
{
    int temp, pivot = arr[lb], start = lb, end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
void main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    int lb = 0, ub = n - 1;
    read_array(arr, n);
    partition(arr, lb, ub);
    quick_sort(arr, lb, ub);
    display_array(arr, n);
}