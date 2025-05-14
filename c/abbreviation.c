#include <stdio.h>
#include <string.h>
void main()
{
    char str[30];
    printf("Enter the string : ");
    gets(str);
    printf("\nThe abbreviation is : %c",str[0]);
    for (int i=1;i<strlen(str);i++)
    {
        if (str[i]==' ')
        {
            printf("%c",str[i+1]);
        }
    }
}