#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *front,*newnode,*rear,*temp;

void enqueue(int value)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->next=NULL;
  if(rear==NULL)
  {
    front=newnode;
    rear=newnode;
  }
  else
  {
    rear->next=newnode;
    rear=newnode;
  }
}

void dequeue()
{
  if(front==NULL)
  {
    printf("Queue is empty \n");
  }
  else if(front==rear)
  {
     temp=front;
     printf("%d deleted \n",temp->data);
     front=NULL;
     rear=NULL;
     free(temp);
  }   
  else
  {
    temp=front;
    front=front->next;
    printf("%d deleted \n",temp->data);
    free(temp);
  }
}

void display()
{
  if (front==NULL)
  {
    printf("Queue is empty \n");
  }
  else
  {
    temp=front;
    printf("List is: \n");
    while(temp->next!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
  }          
}

void main()
{
  int choice=0;
  while(choice!=4)
  {
     printf("Enter choice: \n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
           int value;
           printf("Enter value to push:");
           scanf("%d",&value);
           enqueue(value);
           break;
       case 2:
           dequeue();
           break;
       case 3:
           display();
           break;
       case 4:
           break;
       default:
           printf("Invalid choice \n");
     }
  }
}      
          
    
                               
  





       
   
   
   
     





  
  
  
  
  
  
  
     









  
  
  
  
           
    
   
