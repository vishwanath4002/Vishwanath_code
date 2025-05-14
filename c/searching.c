#include<stdio.h>
#include<stdlib.h>
int arr[50],n;

void create()
{
	printf("Enter size of array : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{	
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
}

void linear()
{
	int x,i,pos,f;
	printf("Enter element to search for : ");
	scanf("%d",&x);
	for(int i=0;i<n;i++)
   	{
       		if(arr[i]==x)
       		{
       			f=1;
           		pos=i+1;
       		}
   	}
   	if(f==1)
   	{
   	    	printf("Element found at %d\n",pos);
   	}
   	else
   	{
       		printf("Element not found\n");
   	}	
}

void binary()
{
	int s,j=0;
	for(int i=1;i<n;i++)
	{
		s=arr[i];
		j=i-1;
		while(j>=0 && s<arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
			arr[j+1]=s;
		}
	}
	printf("Sorted array is : ");
	for(int k=0;k<n;k++)
	{
		printf("%d\t",arr[k]);
	}
	printf("\n");
	int start,x,end;
	printf("Enter element to search for : ");
	scanf("%d",&x);
	start=0;
	end=n-1;
	int mid=(start+end)/2;
	while(start!=end && arr[mid]!=x)
	{
		if(arr[mid]>x)
		{
			end=mid-1;
			mid=(start+end)/2;
		}
		else
		{
			start=mid+1;
			mid=(start+end)/2;
		}
	}
	if(arr[mid]==x)
	{
		printf("Element found at %d\n",mid+1);
	}
	else
	{
		printf("Element not found\n");
	}
}

void main()
{
	int ch;
	while(ch!=4)
	{
		printf("1.Create array\n2.Linear search\n3.Binary search\n4.Exit\n");
		printf("Enter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				linear();
				break;
			case 3:
				binary();
				break;
			case 4: exit(0);
			default:printf("Invalid choice");
		}
	}
}


