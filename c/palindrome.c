#include <stdio.h>
#include <string.h>
void main()
{
    int l,c=0;
    char str[20];
    printf("Enter the string : ");
    gets(str);
    l=strlen(str);
    for (int i=0;i<=l/2;i++)
    {
        if (str[i]==str[l-i-1])
            continue;
        else
            c=1;
            break;
    }
    if (c==0)
        printf("\nIt is a palindrome.");
    else   
        printf("\nIt is not a palindrome.");
}
