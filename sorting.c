// all sorting techniques
#include <stdio.h>
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
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
void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[20];
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k] = b[k];
    }
}
void merge_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
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
void read_array(int arr[], int n)
{
    int i;
    printf("enter the numbers: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int n)
{
    int i;
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void main()
{
    int n;
    printf("enter size of array: ");
    scanf("%d", &n);
    int arr[n], choice;
    int lb = 0, ub = n - 1;
    read_array(arr, n);
    while (choice != 7)
    {
        printf("enter choice:\n1. Bubble sort\n2. Insertion sort\n3. Selection sort\n4. Quick sort\n5. Merge sort\n6. Heap sort\n7. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble_sort(arr, n);
            printf("Bubble sort...\n");
            display_array(arr, n);
            break;
        case 2:
            insertion_sort(arr, n);
            printf("Insertion sort...\n");
            display_array(arr, n);
            break;
        case 3:
            selection_sort(arr, n);
            printf("Selection sort...\n");
            display_array(arr, n);
            break;
        case 4:
            partition(arr, lb, ub);
            quick_sort(arr, lb, ub);
            printf("Quick sort...\n");
            display_array(arr, n);
            break;
        case 5:
            merge_sort(arr, lb, ub);
            printf("Merge sort...\n");
            display_array(arr, n);
            break;
        case 6:
            build_max_heap(arr, n);
            heap_sort(arr, n);
            printf("Heap sort...\n");
            display_array(arr, n);
            break;
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice \n");
        }
    }
}
