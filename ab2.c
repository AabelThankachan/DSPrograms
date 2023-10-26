#include<stdio.h>
void main()
{
int i;
struct student{
   int sub1;
   int sub2;
   int sub3;
   int sub4;
   int sub5;
   int total;
}s[i];
int n;
printf("enter number of students:");
scanf("%d",&n);
for (i=0;i<n;i++)
{
   printf("enter marks of 5 subjects:");
   scanf("%d %d %d %d %d",&s[i].sub1,&s[i].sub2,&s[i].sub3,&s[i].sub4,&s[i].sub5);
   s[i].total=s[i].sub1+s[i].sub2+s[i].sub3+s[i].sub4+s[i].sub5;
}
int arr[20],temp,j;
for (i=0; i<n; i++)
{
  arr[i]=s[i].total;
}
for (i=0; i<n; i++)
{
 for (j=0;j<n-i-1;j++)
 {
   if (arr[j]>arr[j+1])
   {
     temp=arr[j];
     arr[j]=arr[j+1];
     arr[j+1]=temp;
   }
 }
}
for (i=0; i<n; i++)
{
 printf("Total marks is %d,",arr[i]);
 }
 }


        
   
