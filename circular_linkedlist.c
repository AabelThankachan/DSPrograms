#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *front,*rear,*newnode,*temp;

void push_front(int value)
{
   newnode=(struct node *)malloc(sizeof(struct node));  
