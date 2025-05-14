#include <stdio.h>
void main()
{
    int n,e,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements :\n");
    for (i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&e);
    for (i=0;i<n;i++)
    {
        if (e==arr[i])
        {
            break;
        }
    }
    if (i<n)
    {
        printf("Element found at position %d.",i);
    }
    else
    {
        printf("Element not found.");
    }
}