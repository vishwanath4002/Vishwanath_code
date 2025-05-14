#include <stdio.h>
void main()
{
    int n,e,i,j,temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements :\n");
    for (i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nUnsorted array :");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    printf("\nSorted array :");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}