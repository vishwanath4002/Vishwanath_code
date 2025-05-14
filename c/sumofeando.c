#include <stdio.h>
void main()
{
    int n,s,g;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    s=arr[0];
    g=arr[0];
    for(int i=1;i<n;i++)
    {
        if(g<arr[i])
        {
            g=arr[i];
        }
        if(s>arr[i])
        {
            s=arr[i];
        }
    }
    printf("The smallest element is : %d\nThe largest element is : %d",s,g);
}