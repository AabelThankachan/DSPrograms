// sparse representation of a matrix
#include <stdio.h>
void read_matrix(int arr1[20][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
}

void print_matrix(int arr1[20][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t", arr1[i][j]);
        }
        printf("\n");
    }
}

void sparse_rep(int arr1[20][20], int m, int n)
{
    int count = 0, arr2[100][3];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i][j] != 0)
            {
                count++;
            }
        }
    }
    arr2[0][0] = m;
    arr2[0][1] = n;
    arr2[0][2] = count;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i][j] != 0)
            {
                arr2[k][0] = i;
                arr2[k][1] = j;
                arr2[k][2] = arr1[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }
    printf("Sparsity is: %d/%d", m * n - count, m * n);
}

void main()
{
    int arr1[20][20], arr2[20][20], m, n;
    printf("Enter number of rows and columns in the sparse matrix: \n");
    scanf("%d %d", &m, &n);
    printf("Enter elements in sparse matrix: \n");
    read_matrix(arr1, m, n);
    printf("Original matrix is: \n");
    print_matrix(arr1, m, n);
    printf("Triplet representation is: \n");
    printf("Rows\tColumns\tValues \n");
    sparse_rep(arr1, m, n);
}