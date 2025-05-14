#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
    char temp[50];
    int j=0;
    strcpy(temp,str);
    for (int i=strlen(str)-1;i>=0;i--)
    {
        str[j]=temp[i];
        j++;
    }
    puts(str);
}

void main()
{
    char str[50];
    printf("Enter the string : ");
    gets(str);
    printf("\nThe reversed string is : ");
    reverse(str);
}