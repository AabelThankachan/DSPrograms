#include<stdio.h>
#include<math.h>
#define n 5
int front=-1,rear=-1,arr[100];
void c_enqueue()
{
  int item;
  printf("Enter element to add:");
  scanf("%d",&item);
  if (front==-1)
  {
    front=rear=0;
    arr[rear]=item;
  }
  else
  {
    if(front!=((rear+1)%n))
    {
       rear=((rear+1)%n);
       arr[rear]=item;
    }
    else
    {
       printf("Queue is full \n");
    }
  }      
}  

void c_dequeue()
{  
  int item;
  if (front==-1)
  {
    printf("Queue is empty \n");
  }
  else
  {
    item=arr[front];  
    if (front==rear)
    {
      front=rear=-1;
    }
    else
    {
      front=((front+1)%n);
    }
    printf("%d deleted \n",item);
  }
}

void display()
{
   if(front==-1)
   {
      printf("Queue is empty \n");
   }
   else
   {
     printf("Queue is: \n");
     for (int i=front;i<=rear;i++)
     {
        printf("%d  ",arr[i]);
     }
     printf("\n");
   }
}

void main()
{
   int choice;
   while(choice!=4)
   {
      printf("Enter operation: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            c_enqueue();
            break;
         case 2:
            c_dequeue();
            break;
         case 3:
            display();
            break;
         case 4:
            break;
         default:
            printf("Enter valid choice \n");
      }
   }
}







           




  
  
  
  
      
    
    
      
    
    
    
