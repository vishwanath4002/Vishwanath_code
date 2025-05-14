#include <stdio.h>

int size;

void merge(int a[], int l, int m, int r)
{

	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    
    for (i = 0; i < n1; i++) 
    {
        L[i] = a[l + i]; 
	}   
    for (j = 0; j < n2; j++) 
    {
        R[j] = a[m + 1 + j];  
	}
	
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1)
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2)
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int a[], int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

void displayArray(int a[])
{
	for(int i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
}

void main()
{

	int arr[15];
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("%d",arr[size-1]);
	printf("\nUnsorted array :\n");
	displayArray(arr);
	mergeSort(arr,0,size-1);
	printf("\nSorted array :\n");
	displayArray(arr);
	printf("\n");
}
