// array rotation 1
#include <stdio.h>
#include <string.h>
void array_rotate_once(int arr[], int n, char direction)
{
    int i, temp;
    if (direction == 'l')
    {
        temp = arr[0];
        for (i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }
    else if (direction == 'r')
    {
        temp = arr[n - 1];
        for (i = n - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }
}

void array_rotate(int arr[], int n, int freq, char direction)
{
    int i;
    for (i = 0; i < freq; i++)
    {
        array_rotate_once(arr, n, direction);
    }
}
int main()
{
    int i, n, arr[20], freq;
    char direction;
    printf("enter size of array:");
    scanf("%d", &n);
    printf("enter the array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter number of times array is rotated:");
    scanf("%d", &freq);
    printf("enter direction in which array is rotated (r for right and l for left):");
    scanf(" %c", &direction);
    array_rotate(arr, n, freq, direction);
    printf("array after rotation: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    return 0;
}