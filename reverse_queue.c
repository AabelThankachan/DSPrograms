#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *top,*front,*rear,*newnode,*temp;
void enqueue(int value)
{
   newnode=(struct node *)malloc(sizeof(struct node));
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

void display_queue()
{
   if(front==NULL)
   {
      printf("Queue is empty \n");
   }
   else
   {
      temp=front;
      while(temp->next!=NULL)
      {
        printf("%d ",temp->data);
        temp=temp->next;   
      }
      printf("%d",temp->data);
      printf("\n");
   }
}      

void push_stack(int value)
{
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data = value;
   newnode->next = top;
   top = newnode; 
}

int pop_stack()
{
   if(top==NULL)
   {
      printf("Stack is empty \n");
   }
   else
   {   
      int data = top->data;
      temp = top;
      top = top->next;
      free(temp);
      return data;
   }
}   

void reverse_queue()
{
   while (front != NULL) 
   {
      push_stack(front->data);
      temp = front;
      front = front->next;
      free(temp);
   }
   front = NULL;
   rear = NULL;

   while (top != NULL) 
   {
      int data = pop_stack();
      enqueue(data);
   }
}   

void main()
{
   int value,choice=0;
   while(choice!=2)
   {
      printf("Type 1 to add and 2 to stop \n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            printf("enter value to insert in queue:");
            scanf("%d",&value);
            enqueue(value);
            break;
         case 2:
            break;
         default:
            printf("Invalid choice \n");
      }
   }
   printf("Input Queue is: \n");
   display_queue();
   reverse_queue();
   printf("Reverse is: \n");
   display_queue();  
}   
            
                  
            
            
           
