#include <stdio.h>
int m1[10][10], m2[10][10], result[10][10];

void read(int r,int c, int m[10][10])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("\nEnter the element position %d,%d : ",i+1,j+1);
            scanf("%d",&m[i][j]);
            printf("\n");
        }
    }
}
void display(int r,int c, int m[10][10])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}
void multiply(int r1, int c1, int r2, int c2, int m1[10][10], int m2[10][10])
{
    
    for (int r=0;r<r1;r++)
    {
        for (int c=0;c<c2;c++)
        {
            int p=0;
            for (int i=0;i<c1;i++)
            {
                p+=m1[r][i]*m2[i][c];
            }
            result[r][c]=p;
        }
    }
}

void main()
{
    int r1,c1,r2,c2;
    printf("Enter the number of rows and columns of first matrix : ");
    scanf("%d%d",&r1,&c1);
    read(r1,c1,m1);
    display(r1,c1,m1);
    printf("\nEnter the number of rows and columns of second matrix : ");
    scanf("%d%d",&r2,&c2);
    read(r2,c2,m2);
    display(r2,c2,m2);
    multiply(r1,c1,r2,c2,m1,m2);
    display(r1,c2,result);
}