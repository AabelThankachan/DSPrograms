#include<stdio.h>
int arr1[100],arr2[100],top1=-1,top2=-1;
void push1(int item)
{  
     top1++;
     arr1[top1]=item;
}    

void push2(int item)
{   
     top2++;
     arr2[top2]=item;     
}   

void pop2(int item)
{
     item=arr2[top2--];
}

void display1()
{
   printf("Original Stack is: \n");
   for(int i=0;i<=top1;i++)
   {
      printf("%d ",arr1[i]); 
   }
   printf("\n");
} 

void display2()
{
   printf("Auxiliary Stack is: \n");
   for(int i=0;i<=top2;i++)
   {
      printf("%d ",arr2[i]); 
   }
   printf("\n");
} 
          
void main()
{
   int item,choice=0;
   while(choice!=2)
   {  
      printf("Enter choice: 1 to add and 2 to exit \n");
      scanf("%d",&choice);
      if(choice==2)
      {
        break;
      }  
      printf("enter element:");
      scanf("%d",&item); 
      if(top1==-1 && top2==-1)
      {
         push1(item);
         push2(item);
      }   
      else if(item<arr2[top2])
      {
         push1(item);
         pop2(item);
         push2(item);
      }  
      else if(item>arr2[top2])
      {
         push1(item);
      }  
   }
   display1();   
   display2();      
}                    
     

