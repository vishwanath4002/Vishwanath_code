//sum and avg of numbers stored in an array
#include <stdio.h>
void main()
{
    int n,arr[n],i;
    float s=0.0,a;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements :\n");
    for (i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++)
    {
        s+=arr[i];
    }
    a=s/n;
    printf("The sum is %f.\nThe average is %f.",s,a);
}