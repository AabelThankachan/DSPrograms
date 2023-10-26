#include<stdio.h>
void main()
{
   int term1, term2;
   printf("enter degree of first and second polynomial:\n");
   scanf("%d %d",&term1,&term2);
   struct{
      int coeff;
      int expon;
   }p1[term1+1],p2[term2+1],p3[term1+term2+1];
     
   printf("enter first polynomial:\n");
   for(int i=0,j=term1;i<=term1;i++,j--)
   {
       printf("enter coefficient of x^%d:",j);
       scanf("%d",&p1[i].coeff);
       p1[i].expon=j;
   } 
   
   printf("enter second polynomial:\n");
   for(int i=0,j=term2;i<=term2;i++,j--)
   {
       printf("enter coefficient of x^%d:",j);
       scanf("%d",&p2[i].coeff);
       p2[i].expon=j;
   }
   
   int length;
   if(term1>term2)
        length=term1;    
   else
        length=term2;   
   
   int i=0,j=0,k=0;
   while(i<=term1 && j<=term2)
   {
       if(p1[i].expon==p2[j].expon)
       {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expon=p1[i].expon;
            i++;
            j++;
            k++;
       }
       else if(p1[i].expon>p2[j].expon)
       {
            p3[k]=p1[i];
            i++;
            k++;
       }
       else
       {
            p3[k]=p2[j];
            j++;
            k++;
       }
   }
   
   printf("First polynomial is:\n");
   for (i=0;i<term1;i++)
   {
      printf("%dx^%d + ",p1[i].coeff,p1[i].expon);
   }
   printf("%dx^%d \n",p1[term1].coeff,p1[term1].expon);   
   
   printf("Second polynomial is:\n");
   for (i=0;i<term2;i++)
   {
      printf("%dx^%d + ",p2[i].coeff,p2[i].expon);
   }
   printf("%dx^%d \n",p2[term2].coeff,p2[term2].expon);   
      
   printf("Resultant polynomial is:\n");
   for (i=0;i<length;i++)
   {
      printf("%dx^%d + ",p3[i].coeff,p3[i].expon);
   }
   printf("%dx^%d",p3[length].coeff,p3[length].expon);   
}          
       
                           
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
        
