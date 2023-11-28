#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *front=NULL,*rear=NULL,*newnode,*temp;
void enqueue_end(int value)
{
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
   newnode->next=NULL;
   if(rear== NULL)
   {
      front=newnode;
      rear=newnode;
   }
   else
   {
      rear->next=newnode;
      newnode->prev=rear;
      rear=newnode;
   }
}           

void enqueue_front(int value)
{
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
   newnode->next=NULL;
   if(front==NULL)
   {
      front=newnode;
      rear=newnode;
   }
   else
   {
      front->prev=newnode;
      newnode->next=front;
      front=newnode;
   }
}

void dequeue_front()
{
  if(front == NULL)
  {
     printf("Queue is empty \n");
  }
  else if (front==rear)
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
     front->prev=NULL;
     printf("%d deleted \n",temp->data);
     free(temp);
  }
}

void dequeue_end()
{
  if(rear==NULL)
  {
    printf("Queue is empty \n");
  }
  else if(front==rear)
  {
     temp=rear;
     printf("%d deleted \n",temp->data);
     front=NULL;
     rear=NULL;
     free(temp);
  }
  else
  {
     temp=rear;
     rear=rear->prev;
     rear->next=NULL;
     printf("%d deleted \n",temp->data);
     free(temp);
  }
}

void display()
{
   if(front==NULL)
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
     printf("%d",temp->data);
     printf("\n");
   }  
}

void main()
{
   int value,choice=0;
   while(choice!=6)
   {
     printf("Enter choice: \n1. Insert at front \n2. Insert at end \n3. Delete from front \n4. Delete from end \n5. Display \n6. Exit \n");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
          printf("Enter value to insert:");
          scanf("%d",&value);
          enqueue_front(value);
          break;
       case 2:
          printf("Enter value to insert:");
          scanf("%d",&value);
          enqueue_end(value);
          break;   
       case 3:
          dequeue_front();
          break;
       case 4:
          dequeue_end();        
          break;
       case 5:
          display();
          break;
       case 6:
          break;
       default:
          printf("Invalid choice \n");
     }
  }
}                   

     
     
       
     
        

     
     
     
     
     
     
        
  
    





  
     
     
  
     
     
     
        





      
   
   
   
   
      
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
