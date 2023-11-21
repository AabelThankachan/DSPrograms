#include<stdio.h>
#include<stdlib.h>
struct node
{
   int coef;
   int pow;
   struct node *next;
};
struct node *first,*second,*result,*poly,*temp;

void read_poly()
{ 
   int coef,exp;
   temp=(struct node*)malloc(sizeof(struct node));
   *poly=temp;
   printf("enter coefficient and power:");
   scanf("%d %d",&coef,&exp);
   temp->coef=coef;
   temp->pow=exp;
   temp->next=NULL;
}   
  
