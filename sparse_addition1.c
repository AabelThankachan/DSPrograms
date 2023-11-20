// addition of sparse matrices
#include <stdio.h>
void read_sparsemat(int mat[100][100], int r, int c)
{
    int i = 0, j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}
void print_sparsemat(int mat[100][100], int r, int c)
{
    int i = 0, j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void print_tuple(int mat_tup[100][3], int tr)
{
    int i, j;
    printf("Rows\tColumns\tValues \n");
    for (i = 0; i < tr; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat_tup[i][j]);
        }
        printf("\n");
    }
}
int conv_tuple(int mat[100][100], int r, int c, int mat_tup[100][3])
{
    // Sparse to Tuple Form Conversion
    int i, j, cnz = 0, tr = 0, tc = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                cnz++;
                mat_tup[cnz][0] = i;
                mat_tup[cnz][1] = j;
                mat_tup[cnz][2] = mat[i][j];
            }
        }
    }
    mat_tup[0][0] = r;
    mat_tup[0][1] = c;
    mat_tup[0][2] = cnz;
    tr = cnz + 1;
    // tc=3;
    return tr;
}
void sum(int mat1[100][3], int mat2[100][3])
{
    int tr1, tr2, n = 0, mat3[100][3], i, j, k;

    if ((mat1[0][0] == mat2[0][0]) && (mat1[0][1] == mat2[0][1]))
    {

        tr1 = mat1[0][2];
        tr2 = mat2[0][2];
        i = 1;
        j = 1;
        k = 1;
        n = tr1 + tr2;
        while ((i <= tr1) && (j <= tr2))
        {

            if (mat1[i][0] < mat2[j][0])
            {
                mat3[k][0] = mat1[i][0];
                mat3[k][1] = mat1[i][1];
                mat3[k][2] = mat1[i][2];
                i++;
                k++;
            }
            else if (mat1[i][0] > mat2[j][0])
            {
                mat3[k][0] = mat2[j][0];
                mat3[k][1] = mat2[j][1];
                mat3[k][2] = mat2[j][2];
                j++;
                k++;
            }
            else if (mat1[i][1] < mat2[j][1])
            {
                mat3[k][0] = mat1[i][0];
                mat3[k][1] = mat1[i][1];
                mat3[k][2] = mat1[i][2];
                i++;
                k++;
            }
            else if (mat1[i][1] > mat2[j][1])
            {
                mat3[k][0] = mat2[j][0];
                mat3[k][1] = mat2[j][1];
                mat3[k][2] = mat2[j][2];
                j++;
                k++;
            }
            else
            {
                mat3[k][0] = mat1[i][0];
                mat3[k][1] = mat1[i][1];
                mat3[k][2] = mat1[i][2] + mat2[j][2];
                i++;
                j++;
                k++;
            }
        }
        while (i <= tr1)
        {
            mat3[k][0] = mat1[i][0];
            mat3[k][1] = mat1[i][1];
            mat3[k][2] = mat1[i][2];
            i++;
            k++;
        }
        while (j <= tr2)
        {
            mat3[k][0] = mat2[j][0];
            mat3[k][1] = mat2[j][1];
            mat3[k][2] = mat2[j][2];
            j++;
            k++;
        }
        mat3[0][0] = mat1[0][0];
        mat3[0][1] = mat1[0][1];
        mat3[0][2] = k - 1;
        for (i = 0; i < k; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", mat3[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The matrix is incompatible for addition\n");
    }
}
void main()
{
    int mat1[100][100], r1, c1, mat2[100][100], r2, c2;
    int mat1tup[100][3], mat2tup[100][3];
    printf("First matrix:\n");
    printf("Enter the no. of rows:");
    scanf("%d", &r1);
    printf("Enter the no. of columns:");
    scanf("%d", &c1);
    printf("Enter the elements\n");
    read_sparsemat(mat1, r1, c1);
    printf("Second matrix:\n");
    printf("Enter the no. of rows:");
    scanf("%d", &r2);
    printf("Enter the no. of columns:");
    scanf("%d", &c2);
    printf("Enter the elements\n");
    read_sparsemat(mat2, r2, c2);
    printf("The first matrix is : \n");
    print_sparsemat(mat1, r1, c1);
    printf("The second matrix is : \n");
    print_sparsemat(mat2, r2, c2);
    printf("First Matrix in tuple form:\n");
    int tr1 = conv_tuple(mat1, r1, c1, mat1tup);
    print_tuple(mat1tup, tr1);
    printf("Second Matrix in tuple form:\n");
    int tr2 = conv_tuple(mat2, r2, c2, mat2tup);
    print_tuple(mat2tup, tr2);
    printf("Sum of the matrices is:\n");
    sum(mat1tup, mat2tup);
}