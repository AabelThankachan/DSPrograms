#include <stdio.h> //linear search
void read_array(int arr[], int len)
{
    int i;
    printf("enter array elements: \n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
}
long int linear_search(int arr[], int len)
{
    int i, num, flag = 0;
    printf("enter element to search: ");
    scanf("%d", &num);
    for (i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("%d found at position %d", num, i + 1);
    else
        printf("%d not found in array", num);
}
void main()
{
    int len;
    printf("enter size of array:");
    scanf("%d", &len);
    int arr[len];
    read_array(arr, len);
    linear_search(arr, len);
}