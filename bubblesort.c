// bubble sort
#include <stdio.h>
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
}
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
void main()
{
    int n;
    printf("enter how many numbers are there: ");
    scanf("%d", &n);
    int arr[n];
    read_array(arr, n);
    bubble_sort(arr, n);
    display_array(arr, n);
}