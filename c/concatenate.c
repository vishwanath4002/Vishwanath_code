#include <stdio.h>
#include <string.h>
void main()
{
    int j,l1,l2;
    char str1[50];
    char str2[20];
    printf("Enter the first string : ");
    gets(str1);
    printf("\nEnter the second string : ");
    gets(str2);
    l1=strlen(str1);
    l2=strlen(str2);
    str1[l1]='$';
    str2[l2]='$';
    puts(str1);
    puts(str2);
    j=l1+1;
    for (int i=0;i<=l2;i++)
    {
        str1[j]=str2[i];
        j++;
    }
    puts(str1);
}