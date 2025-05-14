#include <stdio.h>
void main()
{
    int n,a[10],*p;
    p=&a[0];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d :",i+1);
        scanf("%d",p+i);
    }
    printf("\nThe array elements are : ");
    for (int i=0; i<n; i++)
    {
        printf("%d\t",*(p+i));
    }
}