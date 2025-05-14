#include <stdio.h>

int factorial(int n)
{
    int f=n;
    for (int i=f-1;i>=2;i--)
    {
        f*=i;
    }
    return f;
}

int factorialrecursion(int a,int b)
{
    if (b==1)
    {
        return a;
    }
    else
    {
        factorialrecursion(a*(b-1),b-1);
    }
}

void main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("The factorial of %d is %d.(without recursion)\nThe factorial of %d is %d.(using recursion)",n,factorial(n),n,factorialrecursion(n,n));
}