// mean,mode and median of array
#include <stdio.h>
void main()
{
    int n, i, arr[20];
    printf("enter size of array:");
    scanf("%d", &n);
    printf("enter array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    float mean, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    mean = (float)sum / n;
    printf("Mean of array is: %f \n", mean);

    float median;
    if (n % 2 == 0)
    {
        median = (float)(arr[n / 2] + arr[(n / 2) - 1]) / 2;
    }
    else
    {
        median = arr[n / 2];
    }
    printf("Median of array is: %f \n", median);

    int mode, j;
    int maxValue = 0,
        maxCount = 0;
    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxValue = arr[i];
        }
    }
    printf("Mode of array is: %d", maxValue);
}
