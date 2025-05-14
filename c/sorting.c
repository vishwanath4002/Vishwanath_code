#include <stdio.h>
#include <stdlib.h>

int n;
int arr[20];
void Bsort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Enter the element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Sorted array using Bubble sort :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void Isort()
{
	int j,item;
	int c=0;
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the element %d : ",i+1);
		scanf("%d",&arr[i]);
		c++;
		for(int i=1;i<c;i++)
		{
			item=arr[i];
			j=i-1;
			while(j>=0 && item<arr[j])
			{
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=item;
		}
		printf("Sorted array:");
		for(int i=0;i<c;i++)
		{
			printf("%d\t",arr[i]);
		}
	}
	printf("\n");
}
void Ssort()
{	
	int i,j,min;
	for(i=0;i<n;i++)
	{
		printf("Enter the element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}	
		if (min!=i)
		{
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
	printf("Sorted array using Selection sort :\n");
	for(i=0;i<n;i++)
	{
			printf("%d\t",arr[i]);
	}
	printf("\n");
}					
void main()
{
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int i;
	while(1)
	{
		int ch;
		printf("\n1.Bubble sort\n2.Insertion sort\n3.Selection sort\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: Bsort();
				break;
			case 2: Isort();
				break;
			case 3: Ssort();
				break;
			case 4: exit(0);
			default: printf("Invalid choice");
		}
	}
}