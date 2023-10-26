#include<stdio.h>
void main()
{
  int arr1[20][20],arr2[20][20],nnz1,nnz2;
  printf("enter number of non-zero elements in matrix 1:");
  scanf("%d",&nnz1);
  printf("enter elements in representation of matrix 1: \n");
  for (int i=0;i<=nnz1;i++)
  {
    for(int j=0;j<3;j++)
    {
      scanf("%d",&arr1[i][j]);
    }
  }
  printf("enter number of non-zero elements in matrix 2:");
  scanf("%d",&nnz2);
  printf("enter elements in representation of matrix 2: \n");
  for (int i=0;i<=nnz2;i++)
  {
    for(int j=0;j<3;j++)
    {
      scanf("%d",&arr2[i][j]);
    }
  }
  if (arr1[0][0]!=arr2[0][0] | arr1[0][1]!=arr2[0][1])
  {
    printf("Addition not possible");
  }
  else
  {
    int arr3[20][20],i=0;j=0;k=0;
    for (i=1; i<arr1[0][0];i++)
    {
      for (j=0; j<arr1[0][1]; j++)
      {
        if (arr1[i][j]>arr2[i][j])
        {
          for(j=0;j<3;j++)
          {
            arr3[i][j]=arr2[i][j];
          } 
          j++;
          k++;
        }
        else if(arr1[i][j]<arr2[i][j])
        { 
          for (j=0;j<3;j++)
          {
            arr3[i][j]=arr1[i][j];
          }  
          i++;
          k++;
        }
        else
        {
          for (j=0;j<2;j++)
          {
            arr3[i][j]=arr1[i][j];
          }
          arr3[i][2]=arr1[i][2]+arr2[i][2];
          i++;
          j++;
          k++;
        }
      }
    }
    printf("Rows\tColumns\tValues");
    for (i=0;i<k;i++)
    {
      for(j=0;j<3;j++)
      { 
        printf("%d\t",arr3[i][j]);
      }
      printf("\n");
    }    
  }
}    
            
          
              
        
        
        
        
        
        
        
        
        
        
        
      
      
      
