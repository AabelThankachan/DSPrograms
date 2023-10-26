#include<stdio.h>
int pow1(int base,int exp)
{
  int result=1;
  while(exp!=0)
  {
    result*=base;
    --exp;
  }
  return result;      
}        
     
void main()
{
   int term1;
   printf("enter degree of polynomial:");
   scanf("%d",&term1);
   struct{
      int coeff;
      int expon;
   } p[term1+1];  
   
   for(int i=0,j=term1;i<=term1;i++,j--)
   {
      printf("enter coefficient of x^%d:",j);
      scanf("%d",&p[i].coeff);
      p[i].expon=j;
   }
   
   printf("the polynomial is: \n");
   for(int i=0;i<term1;i++)
   {
      printf("%dx^%d + ",p[i].coeff,p[i].expon);
   }   
   printf("%dx^%d \n",p[term1].coeff,p[term1].expon);
   
   int val,sum=0;
   printf("enter value at which polynomial is evaluated:");
   scanf("%d",&val);
   for (int i=0;i<=term1;i++)
   { 
      sum=sum+p[i].coeff*pow1(val,p[i].expon);
   }
   printf("Value of polynomial at %d is %d",val,sum);    
}   








