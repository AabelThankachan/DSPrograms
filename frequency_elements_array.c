// frequency of elements in an array
#include <stdio.h>
void main()
{
    int n, i, j, arr[20];
    printf("enter size of array:");
    scanf("%d", &n);
    int fr[n], visited = -1;
    printf("enter array elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                fr[j] = visited;
            }
        }
        if (fr[i] != visited)
        {
            fr[i] = count;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (fr[i] != visited)
        {
            printf("%d occurs %d times \n", arr[i], fr[i]);
        }
    }
}