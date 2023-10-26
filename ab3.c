#include<stdio.h>
long int binary_search(int arr[],int n)
{
	   int num,flag=0;
	   printf("enter element to search:");
	   scanf("%d",&num);
	   int low=0;int high=n-1;int mid=(low+high)/2;
	   while (high>=low)
	   {
	      if(num==arr[mid])
	      {
	        flag=1;
	        break;
	      }
	      else if(num>arr[mid])
	      {
	        low=mid+1;
	        mid=(low+high)/2;
	      }
	      else
	      {
	        high=mid-1;
	        mid=(low+high)/2;
	      }
	   }
	   if (flag==1)
	   	printf("%d is at position %d",num,mid+1);
	   else
	   	printf("%d not in array",num); 	     	        	          
}

long int selection_sort(int arr[],int n)
{
	int i,j,min,temp;
	for (i=0;i<n;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
		{
			if (arr[min]>arr[j])
				min=j;
		}
		if (min !=i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	printf("sorted array is: \n");
	for (i=0; i<n; i++)
	{
		printf("%d,",arr[i]);
	}
}

long int linear_search(int arr[],int n)
{
	int i,num1,flag=0;
	printf("enter number to search: \n");
	scanf("%d",&num1);
	for (i=0;i<n;i++)
	{
		if (arr[i]==num1)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
		printf("%d is at position %d",num1,i+1);
	else
		printf("%d is not in array",num1);
}

long int bubble_sort(int arr[],int n)
{
	int i,j,temp;
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("the sorted array is: \n");
	for (i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
}						
											
void main()
{
	int i,n,arr[20],op;
	printf("enter size of list:");
	scanf("%d",&n);
	printf("enter the array elements: \n");
	for (i=0;i<n;i++)
	{
	   scanf("%d",&arr[i]);
	}
	printf("enter operation: \n1.Binary Search \n2.Selection Sort \n3.Linear Search \n4.Bubble Sort \n");
	scanf("%d",&op);	
	switch(op)
	{
		case 1:
			binary_search(arr,n);
			break;
		case 2:
			selection_sort(arr,n);
			break;	
		case 3:
			linear_search(arr,n);
			break;
		case 4:
			bubble_sort(arr,n);
			break;		
		default:
			printf("enter valid operation");	
	}		
}	
		

