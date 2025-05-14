#include <stdio.h>
void main()
{
    int a,b,*pa=&a,*pb=&b,t;
    printf("Enter value of a and b : ");
    scanf("%d%d",&a,&b);
    t=*pa;
    *pa=*pb;
    *pb=t;
    printf("\nAfter swapping a is %d and b is %d.",a,b);
}