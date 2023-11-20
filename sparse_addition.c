// addition of 2 sparse matrices whose triplet representation is given
#include <stdio.h>
void read_first(int arr1[100][3], int nnz1)
{
    for (int i = 0; i <= nnz1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
}

void read_second(int arr2[100][3], int nnz2)
{
    for (int i = 0; i <= nnz2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
}

void print_first(int arr1[100][3], int nnz1)
{
    for (int i = 0; i <= nnz1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }
}

void print_second(int arr2[100][3], int nnz2)
{
    for (int i = 0; i <= nnz2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }
}

void sum(int arr1[100][3], int arr2[100][3], int nnz1, int nnz2)
{
    int arr3[100][3], i, j, k;
    if (arr1[0][0] == arr2[0][0] && arr1[0][1] == arr2[0][1])
    {
        i = 1, j = 1, k = 1;
        while ((i <= nnz1) && (j <= nnz2))
        {
            if (arr1[i][0] < arr2[j][0])
            {
                arr3[k][0] = arr1[i][0];
                arr3[k][1] = arr1[i][1];
                arr3[k][2] = arr1[i][2];
                i++;
                k++;
            }
            else if (arr1[i][0] > arr2[j][0])
            {
                arr3[k][0] = arr2[j][0];
                arr3[k][1] = arr2[j][1];
                arr3[k][2] = arr2[j][2];
                j++;
                k++;
            }
            else if (arr1[i][1] < arr2[j][1])
            {
                arr3[k][0] = arr1[i][0];
                arr3[k][1] = arr1[i][1];
                arr3[k][2] = arr1[i][2];
                i++;
                k++;
            }
            else if (arr1[i][1] > arr2[j][1])
            {
                arr3[k][0] = arr2[j][0];
                arr3[k][1] = arr2[j][1];
                arr3[k][2] = arr2[j][2];
                j++;
                k++;
            }
            else
            {
                arr3[k][0] = arr1[i][0];
                arr3[k][1] = arr1[i][1];
                arr3[k][2] = arr1[i][2] + arr2[j][2];
                i++;
                j++;
                k++;
            }
        }
        while (i <= nnz1)
        {
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k][2] = arr1[i][2];
            i++;
            k++;
        }
        while (j <= nnz2)
        {
            arr3[k][0] = arr2[j][0];
            arr3[k][1] = arr2[j][1];
            arr3[k][2] = arr2[j][2];
            j++;
            k++;
        }
        arr3[0][0] = arr1[0][0];
        arr3[0][1] = arr1[0][1];
        arr3[0][2] = k - 1;
        for (i = 0; i < k; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", arr3[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Cannot add the matrices");
    }
}

void main()
{
    int nnz1, nnz2, arr1[100][3], arr2[100][3];
    printf("enter number of non-zero values in first matrix: \n");
    scanf("%d", &nnz1);
    printf("enter number of non-zero values in second matrix: \n");
    scanf("%d", &nnz2);
    printf("Enter triplet representation of first matrix: \n");
    read_first(arr1, nnz1);
    printf("Enter triplet representation of second matrix: \n");
    read_second(arr2, nnz2);
    printf("First matrix is: \n");
    printf("Rows\tColumns\tValues \n");
    print_first(arr1, nnz1);
    printf("Second matrix is: \n");
    printf("Rows\tColumns\tValues \n");
    print_second(arr2, nnz2);
    printf("Triplet representation of their sum is: \n");
    printf("Rows\tColumns\tValues \n");
    sum(arr1, arr2, nnz1, nnz2);
}