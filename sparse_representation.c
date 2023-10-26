#include<stdio.h>
void read_sparsematrix(int arr[100][100],int m,int n)
{
   for (int i=0;i<m;i++)
   {
     for (int j=0;j<n;j++)
     {
       scanf("%d",&arr[i][j]);
     }
   }
}

void print_sparsematrix(int arr[100][100],int m,int n)
{
  for (int i=0;i<m;i++)
  {
    for (int j=0;j<n;j++)
    {
      printf("%d \t",arr[i][j]);
    }
    printf("\n");
  }
}

void sparse_rep(int arr[100][100],int m,int n)
{
  int count=0,arr1[100][3];
  for (int i=0; i<m; i++)
  {
    for (int j=0; j<n; j++)
    {
      if (arr[i][j]!=0)
      {
        count++;
      }
    }
  }
  arr1[0][0]=m;
  arr1[0][1]=n;
  arr1[0][2]=count;
  int k=1;
  for (int i=0; i<m; i++)
  {
    for (int j=0; j<n; j++)
    {
      if (arr[i][j]!=0)
      {
        arr1[k][0]=i;
        arr1[k][1]=j;
        arr1[k][2]=arr[i][j];
        k++;       
      }
    }
  }
  for (int i=0;i<=count;i++)
  {
    for (int j=0;j<3;j++)
    {
       printf("%d\t",arr1[i][j]);
    }
    printf("\n");
  }
  printf("Sparsity is: %d/%d",m*n-count,m*n);         
}  

void main()
{
  int arr[100][100],arr1[100][100],m,n;
  printf("Enter number of rows and columns in the sparse matrix: \n");
  scanf("%d %d",&m,&n);
  printf("Enter elements in sparse matrix: \n");
  read_sparsematrix(arr,m,n);
  printf("The matrix is: \n");
  print_sparsematrix(arr,m,n);
  printf("Sparse representation is: \n");
  printf("Rows\tColumns\tValues \n");
  sparse_rep(arr,m,n);
}        
           
