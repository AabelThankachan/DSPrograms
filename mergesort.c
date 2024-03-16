// merge sort
#include <stdio.h>
void read_array(int a[], int n)
{
    printf("enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display_array(int a[], int n)
{
    printf("sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}
void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[20];
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}
void merge_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void main()
{
    int n;
    printf("enter size of array: ");
    scanf("%d", &n);
    int a[n];
    int lb = 0, ub = n - 1;
    read_array(a, n);
    merge_sort(a, lb, ub);
    display_array(a, n);
}