#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};   
struct node *head,*newnode,*temp;

void create_list()
{
   head=0;
   int n;
   printf("Enter number of elements:");
   scanf("%d",&n);
   printf("enter elements: \n");
   for (int i=0;i<n;i++)
   {
      newnode=(struct node*) malloc(sizeof(struct node));
      scanf("%d",&newnode->data);
      newnode->next=0;
      if(head==0)
      {
        head=temp=newnode;
      }
      else
      {
        temp->next=newnode;
        temp=newnode;
      }
   }
   temp=head;
   printf("List is: ");
   while (temp!=0)
   {
     printf("%d ",temp->data);
     temp=temp->next;
   }
   printf("\n");
}

void add_afterdata()
{
  struct node *p;
  int after,num;
  temp=head;
  printf("enter element after which you want to insert:");
  scanf("%d",&after);
  printf("enter element to insert:");
  scanf("%d",&num);  
  while(temp->data != after)
  {
     temp=temp->next;
  }
  if (temp==0)
  {
    printf("List is empty");
  }
  else
  {  
    newnode=(struct node*) malloc(sizeof(struct node));
    p=temp->next;
    temp->next=newnode;
    newnode->data=num;
    newnode->next=p;
    printf("List is: ");
    temp=head;
    while (temp!=0)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
    printf("\n");
  }
}       

void add_beforedata()
{ 
   struct node *prev;
   int before,num;
   temp=head;
   printf("enter element before which you want to insert:");
   scanf("%d",&before);
   printf("enter element to insert:");
   scanf("%d",&num);
   while(temp->data != before)
   {
      prev=temp;
      temp=temp->next;
   }
   if (temp==0)
   {
      printf("List is empty");
   }
   else
   {
     newnode=(struct node*) malloc(sizeof(struct node));
     prev->next=newnode;
     newnode->data=num;
     newnode->next=temp;
     printf("List is: ");
     temp=head;
     while (temp!=0)
     {
       printf("%d ",temp->data);
       temp=temp->next;
     }
     printf("\n"); 
   }       
}      

void add_position()
{
   temp=head;
   int i,pos,count=0;
   printf("enter position at which you want to add:");
   scanf("%d",&pos);
   while(temp->next!=0)
   {
      count++;
      temp=temp->next;
   } 
   if (pos>count)
   {
      printf("Invalid position");
   }
   else
   {
     temp=head;
     while(i<pos)
     {
        temp=temp->next;
        i++;
     }
     newnode=(struct node*) malloc(sizeof(struct node));
     printf("enter element:");
     scanf("%d",&newnode->data);
     newnode->next=temp->next;
     temp->next=newnode;
   }
   temp=head;
   while (temp!=0)
   {
     printf("%d ",temp->data);
     temp=temp->next;
   }
   printf("\n"); 
}               

void delete_data()
{
   struct node *prev;
   int num;
   printf("enter element to delete:");
   scanf("%d",&num);  
   temp=head;
   while(temp->data!=num)
   {
     prev=temp;
     temp=temp->next;
   }  
   prev->next=temp->next;
   printf("List is: ");
   temp=head;
   while (temp!=0)
   {
     printf("%d ",temp->data);
     temp=temp->next;
   }
   printf("\n"); 
}     

void smallest_element()
{
   int min;
   temp=head->next;
   min=temp->data;
   while(temp!=0)
   {
     if(temp->data >min)
     {
        min=temp->data;
        temp=temp->next;
     }
   }
   printf("smallest element is %d \n",min);
}           
     
void search()
{
   int num,count=1;
   temp=head;
   printf("enter element to search for:");
   scanf("%d",&num);
   while (temp->data!=num)
   {
     temp=temp->next;
     count++;
   }   
   printf("%d at position %d \n",num,count);
}      

void main()
{
  int choice=0;
  while(choice!=9)
  {
  printf("Enter choice:\n1.Create list \n2.Insert node after data \n3.Insert node before data \n4.Insert node at a position \n5.Delete value \n6.Smallest element \n8.Search element \n9.Exit \n");
  scanf("%d",&choice);
  switch(choice)
  {
     case 1:     
          create_list();
          break;
     case 2:
          add_afterdata();
          break;
     case 3:
          add_beforedata();
          break;     
     case 4:
          add_position();
          break; 
     case 5:
          delete_data();
          break;  
     case 6:
          smallest_element();
          break;     
     case 8:
          search();
          break;            
     case 9:
          break;
     default:
          printf("Invalid choice \n");
  }
  }                                                
}  








     
          
   
