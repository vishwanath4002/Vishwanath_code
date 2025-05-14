#include <stdio.h>
int sum(int a[10],int n)
{
    int *p,s=0;
    p=&a[0];
    for (int i=0;i<n;i++)
    {
        s+=*(p+i);
    }
    return s;
}
void main()
{
    int n,a[10],*p,s=0;
    p=&a[0];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        printf("Enter element %d :",i+1);
        scanf("%d",p+i);
    }
    printf("\nThe sum of elements is : %d",sum(a,n));
}