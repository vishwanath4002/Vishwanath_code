#include <stdio.h>
#include <stdlib.h>
int a[50],n;
int partition(int low,int high)
{
	int i,j;
	int pivot=a[low];
	i=low+1; j=high;
	while(1)
	{
		while((i<j) && (pivot>a[i]))
		{
			i++;
		}
		while(pivot<a[j])
		{
		    	j-- ;
		}
		if (i<j)
		{
		    	int t=a[i];
		    	a[i]=a[j];
		    	a[j]=t;
		}
		else
		{
		    	int t1=a[low];
		    	a[low]=a[j];
		    	a[j]=t1;
		    	return j;
		}
	}
}
void QSort(int first,int last)
{
	if (first<last)
	{
       		int p=partition(first,last);
        	QSort(first, p-1);
        	QSort(p+1, last);
    	}
    	return;
}
void main()
{
	printf("Enter no of elememts in the array : ");
	scanf("%d",&n);
    for (int i=0;i<n;i++)
	{
       	printf("Enter element %d : ",i+1);
       	scanf("%d",&a[i]);
   	}
   	printf("\nUnsorted array is : ");
   	for(int i=0;i<n;i++)
   	{
   		printf("%d\t",a[i]);
   	}
   	QSort(0, n-1);
   	printf("\nSorted array is : ");
   	for (int i=0;i<n;i++)
   	{
       	printf("%d\t", a[i]);
   	}
   	printf("\n");
}
