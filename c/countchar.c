#include <stdio.h>
#include <string.h>
void main()
{
    int v=0,c=0,s=0;
    char str[50];
    printf("Enter the string : ");
    gets(str);
    str[strlen(str)]='$';
    for (int i=0;i<strlen(str)-1;i++)
    {
        if (str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
            v++;
        else if (str[i]>='A' && str[i]<='z')
            c++;
        else if (str[i]==' ')
            s++;
    }
    printf("\nThe number of vowels is : %d\nThe number of consonants is : %d\nThe number of spaces is : %d",v,c,s);
}