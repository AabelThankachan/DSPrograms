// sparse representation of a matrix using pointers
#include <stdio.h>

// Structure to represent a sparse matrix in CSR format without malloc
struct CSRMatrix
{
    int rows;
    int cols;
    int nnz;              // Number of non-zero elements
    int values[1000];     // Array to store non-zero values
    int col_indices[100]; // Array to store column indices of non-zero values
    int row_indices[100]; // Array to store row indices of non-zero values
    int row_ptr[100 + 1]; // Array to store row pointers
};

// Function to create a CSR matrix from given matrix
void createCSRMatrix(int numRows, int numCols, int arr[100][100], struct CSRMatrix *csr)
{
    csr->rows = numRows;
    csr->cols = numCols;
    csr->nnz = 0;
    int nnz_index = 0;
    int row_start = 0;

    // Convert the given matrix to CSR format
    for (int i = 0; i < numRows; i++)
    {
        csr->row_ptr[i] = row_start;
        for (int j = 0; j < numCols; j++)
        {
            if (arr[i][j] != 0)
            {
                csr->values[nnz_index] = arr[i][j];
                csr->col_indices[nnz_index] = j;
                csr->row_indices[nnz_index] = i; // Capture the row index
                nnz_index++;
                csr->nnz++;
            }
        }
        row_start += nnz_index - row_start;
    }
    csr->row_ptr[numRows] = nnz_index; // Set the last element of row_ptr
}

void main()
{
    int numRows, numCols;
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);
    int arr[100][100];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    struct CSRMatrix csrMatrix;
    createCSRMatrix(numRows, numCols, arr, &csrMatrix);

    // Print the CSR matrix
    printf("CSR Matrix:\n");
    printf("Rows: %d, Cols: %d, Non-Zero Elements: %d\n", csrMatrix.rows, csrMatrix.cols, csrMatrix.nnz);
    printf("Row Indices: ");
    for (int i = 0; i < csrMatrix.nnz; i++)
    {
        printf("%d ", csrMatrix.row_indices[i]);
    }
    printf("\nCol Indices: ");
    for (int i = 0; i < csrMatrix.nnz; i++)
    {
        printf("%d ", csrMatrix.col_indices[i]);
    }
    printf("\nValues: ");
    for (int i = 0; i < csrMatrix.nnz; i++)
    {
        printf("%d ", csrMatrix.values[i]);
    }
    printf("\n");
}
