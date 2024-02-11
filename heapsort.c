// heap sort
#include <stdio.h>
void read_array(int arr[], int n)
{
    printf("enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int n)
{
    printf("sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void build_max_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heap_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void main()
{
    int n;
    printf("enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    read_array(arr, n);
    build_max_heap(arr, n);
    heap_sort(arr, n);
    display_array(arr, n);
}