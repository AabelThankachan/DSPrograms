#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *top,*newnode,*temp;

void push(int num)
{
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=num;
  if (top==NULL)
  {
    newnode->next=NULL;
  }
  else
  {
    newnode->next=top;
  }
  top=newnode;
}

void pop()
{
  if (top==NULL)
  {
     printf("Stack is empty \n");
  }
  else
  {
    temp=top;
    top=top->next;
    printf("%d popped \n",temp->data);
    free(temp);
  }
}

void peek()
{
  if(top==NULL)
  {
     printf("Stack is empty \n");
  }
  else
  {
     printf("%d is topmost item \n",top->data);
  }   
}

void display()
{
   if (top==NULL)
   {
     printf("Stack is empty \n");
   }
   else
   {
     printf("List is: \n");
     temp=top;
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
  while(choice!=5)
  {
     printf("Enter choice: \n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit \n");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
           int num;
           printf("Enter value to push:");
           scanf("%d",&num);
           push(num);
           break;
       case 2:
           pop();
           break;
       case 3:
           peek();
           break;
       case 4:
           display();
           break;
       case 5:
           break;
       default:
           printf("Invalid choice \n");
     }
  }
}      
