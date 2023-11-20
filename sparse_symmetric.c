// checking for sparse symmetric matrix
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

void sparse_symmetric(int arr1[100][3], int nnz)
{
    int arr2[100][3];
    for (int i = 0; i <= nnz; i++)
    {
        arr2[i][0] = arr1[i][1];
        arr2[i][1] = arr1[i][0];
        arr2[i][2] = arr1[i][2];
    }
    int i, j, t1, t2, t3, flag = 0;
    for (i = 1; i < nnz; i++)
    {
        for (j = i + 1; j <= nnz; j++)
        {
            if (arr2[i][0] > arr2[j][0])
            {
                t1 = arr2[i][0];
                t2 = arr2[i][1];
                t3 = arr2[i][2];
                arr2[i][0] = arr2[j][0];
                arr2[i][1] = arr2[j][1];
                arr2[i][2] = arr2[j][2];
                arr2[j][0] = t1;
                arr2[j][1] = t2;
                arr2[j][2] = t3;
            }
            else if (arr2[i][0] == arr2[j][0])
            {
                if (arr2[i][1] > arr2[j][1])
                {
                    t1 = arr2[i][0];
                    t2 = arr2[i][1];
                    t3 = arr2[i][2];
                    arr2[i][0] = arr2[j][0];
                    arr2[i][1] = arr2[j][1];
                    arr2[i][2] = arr2[j][2];
                    arr2[j][0] = t1;
                    arr2[j][1] = t2;
                    arr2[j][2] = t3;
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
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i <= nnz; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Matrix is sparse symmetric");
    }
    else
    {
        printf("Matrix is not sparse symmetric");
    }
}
void main()
{
    int nnz, arr1[100][3];
    printf("enter number of non-zero values in matrix: ");
    scanf("%d", &nnz);
    read_matrix(arr1, nnz);
    print_matrix(arr1, nnz);
    sparse_symmetric(arr1, nnz);
}