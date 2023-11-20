// finding transpose of a sparse matrix
#include <stdio.h>

void read_matrix(int arr1[100][3], int nnz)
{
    printf("Enter triplet representation of matrix: \n");
    for (int i = 0; i <= nnz; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
}

void print_matrix(int arr1[100][3], int nnz)
{
    printf("Matrix is: \n");
    printf("Rows\tColumns\tValues \n");
    for (int i = 0; i <= nnz; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }
}

void transpose(int arr1[100][3], int nnz)
{
    int temp[100], i, j, t1, t2, t3;
    for (i = 0; i <= nnz; i++)
    {
        temp[i] = arr1[i][0];
    }
    for (i = 0; i <= nnz; i++) // exchanging row and column indexes
    {
        arr1[i][0] = arr1[i][1];
        arr1[i][1] = temp[i];
    }
    for (int i = 1; i < nnz; i++)
    {
        for (int j = i + 1; j <= nnz; j++)
        {
            if (arr1[i][0] > arr1[j][0])
            {
                t1 = arr1[i][0];
                t2 = arr1[i][1];
                t3 = arr1[i][2];
                arr1[i][0] = arr1[j][0];
                arr1[i][1] = arr1[j][1];
                arr1[i][2] = arr1[j][2];
                arr1[j][0] = t1;
                arr1[j][1] = t2;
                arr1[j][2] = t3;
            }
            else if (arr1[i][0] == arr1[j][0])
            {
                if (arr1[i][1] > arr1[j][1])
                {
                    t1 = arr1[i][0];
                    t2 = arr1[i][1];
                    t3 = arr1[i][2];
                    arr1[i][0] = arr1[j][0];
                    arr1[i][1] = arr1[j][1];
                    arr1[i][2] = arr1[j][2];
                    arr1[j][0] = t1;
                    arr1[j][1] = t2;
                    arr1[j][2] = t3;
                }
            }
        }
    }

    printf("Transpose is: \n");
    printf("Rows\tColumns\tValues \n");
    for (i = 0; i <= nnz; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int nnz, arr1[100][3];
    printf("enter number of non-zero values in matrix: ");
    scanf("%d", &nnz);
    read_matrix(arr1, nnz);
    print_matrix(arr1, nnz);
    transpose(arr1, nnz);
}