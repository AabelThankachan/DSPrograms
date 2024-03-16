// array rotation 2
#include <stdio.h>

void rotateArray(int arr[], int n, int freq, int direction)
{
    int i, j, temp;
    if (direction == 1) // rotate left
    {
        for (i = 0; i < freq; i++)
        {
            temp = arr[0];
            for (j = 0; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = temp;
        }
    }
    else // rotate right
    {
        for (i = 0; i < freq; i++)
        {
            temp = arr[n - 1];
            for (j = n - 1; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
        }
    }
}

int main()
{
    int i, n, arr[20], freq;
    int direction;
    printf("enter size of array:");
    scanf("%d", &n);
    printf("enter the array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the direction of rotation (1 for left, 2 for right): ");
    scanf("%d", &direction);

    printf("Enter the number of times to rotate: ");
    scanf("%d", &freq);

    rotateArray(arr, n, freq, direction);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}