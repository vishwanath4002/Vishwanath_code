#include <stdio.h>
#include <string.h>

struct employee
{
    char name[20];
    char id[10];
    float salary;
};

void main()
{
    int n;
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    struct employee e[n];
    printf("Enter the details of the employees\n");
    
    for(int i=0;i<n;i++)
    {
        printf("\nEmployee %d\n````````````",i+1);
        printf("\nEnter the name : ");
        getchar();
        gets(e[i].name);
        printf("\nEnter the id : ");
        gets(e[i].id);
        printf("\nEnter the salary : ");
        scanf("%f",&e[i].salary);
        printf("\n---------------------------------------------------------\n\n");
    }

    printf("\nThe details of the employees are :");
    for(int i=0;i<n;i++)
    {
        printf("\nEmployee %d\n````````````",i+1);
        printf("\nName : ");
        puts(e[i].name);
        printf("\nid : ");
        puts(e[i].id);
        printf("\nSalary : %f",e[i].salary);
        printf("\n---------------------------------------------------------\n\n");
    }
}