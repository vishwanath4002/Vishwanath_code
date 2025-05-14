#include <stdio.h>
void main()
{
    int a,b,*pa,*pb,sum;
    pa=&a;
    pb=&b;
    printf("Enter the two numbers : ");
    scanf("%d%d",&*pa,&*pb);
    sum=*pa+*pb;
    printf("\nThe sum is : %d",sum);
}