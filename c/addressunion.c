#include <stdio.h>
#define C_SIZE 15
union address
{
    char name[C_SIZE],hname[C_SIZE],cname[C_SIZE],state[C_SIZE],pin[C_SIZE];
}a;

void main()
{
    printf("Enter the name : ");
    gets(a.name);
    printf("\nName : %s",a.name);
    printf("\nEnter the house name : ");
    gets(a.hname);
    printf("\nHouse name : %s",a.hname);
    printf("\nEnter the city name : ");
    gets(a.cname);
    printf("\nCity name : %s",a.cname);;
    printf("\nEnter the state : ");
    gets(a.state);
    printf("\nState : %s",a.state);
    printf("\nEnter the pin : ");
    gets(a.pin);
    printf("\npin : %s",a.pin);
}