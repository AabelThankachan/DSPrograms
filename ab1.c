#include <stdio.h>
void main()
{
int i, len, arr[20], op;
printf("enter number of elements:");
scanf("%d",&len);
printf("enter array elements:");
for (i=0;i<len;i++)
{
  scanf("%d",&arr[i]);
}
printf("Enter operation: \n 1. Insert element \n 2. Delete element \n 3.Search element \n");
scanf("%d",&op);
switch(op)
{
  case 1:
     int j,add;
     printf("enter element to be added:");
     scanf("%d",&add);
     arr[len]=add;
     printf("new array is:");
     for (j=0;j<=len;j++)
     printf("%d,",arr[j]);
     break;
  case 2:
     int k;
     printf("enter position of element to delete:");
     scanf("%d",&k);
     for (i=k-1;i<len;i++)
     {
       arr[i]=arr[i+1];
     }
     printf("new array is:");
     for (i=0; i<len-1; i++)
     printf("%d,",arr[i]);
     break;
  case 3:
     int  num, flag=0;
     printf("enter element to search:");
     scanf("%d",&num);
     for (i=0; i<len; i++)
     {
       if (arr[i]==num)
       {
         flag=1;
         printf("%d is at position %d",num,i+1);
         break;
       }
     }
     if (flag==0)
     printf("not present in array");
     break;
  default:
     printf("enter valid operation");
}
}        
       
     
     
     
     
         
     
     
     
     
     

