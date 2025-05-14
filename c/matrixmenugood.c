#include <stdio.h>

int m1[10][10],m2[10][10];

void readm(int a, int b,int m[a][b])
{
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            printf("\nEnter element at [%d,%d] : ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
}
void displaym(int r, int c,int m[r][c])
{
    printf("\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }    
}
void addm(int r1,int c1,int r2,int c2, int a[r1][c1],int b[r2][c2])
{
    if (r1==r2 && c1==c2)
    {
        int sum[r1][c1];
        for (int i=0;i<r1;i++)
        {
            for (int j=0;j<c1;j++)
            {
                sum[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("The sum is : \n");
        displaym(r1,c1,sum);
    }
    else
        printf("The orders of the matrices are incompatible for addition.");
}
void multiplym(int r1,int c1,int r2,int c2, int a[r1][c1],int b[r2][c2])
{
    if (c1==r2)
    {
        int p[r1][c2];
        for (int r=0;r<r1;r++)
        {
            for (int c=0;c<c2;c++)
            {
                int s=0;
                for (int i=0;i<c1;i++)
                {
                    s+=a[r][i]*b[i][c];
                }
                p[r][c]=s;
            }
        }
        displaym(r1,c2,p);
    }
    else
        printf("The orders of the matrices are incompatible for multiplication.");
}
void transpose(int r, int c,int m[r][c])
{
    int t[c][r];
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            t[j][i]=m[i][j];
        }
    }
    printf("\nThe transpose of the matrix is : ");
    displaym(c,r,t);
}
void main()
{
    int r1,r2,c1,c2;
    int c;
    while (c!=4)
    {
        printf("__________________________");
        printf("\n1.Matrix addition\n2.Matrix multiplication.\n3.Transpose.\n4.Exit\nEnter your choice : ");
        scanf("%d",&c);
        printf("\n");
        switch (c)
        {
            case 1:
                printf("First matrix\n");
                printf("\nEnter the number of rows and columns : ");
                scanf("%d%d",&r1,&c1);
                readm(r1,c1,m1);
                displaym(r1,c1,m1);
                printf("\nSecond matrix\n");
                printf("\nEnter the number of rows and columns : ");
                scanf("%d%d",&r2,&c2);
                readm(r2,c2,m2);
                displaym(r2,c2,m2);
                addm(r1,c1,r2,c2,m1,m2);
                break;
            case 2:
                printf("First matrix\n");
                printf("\nEnter the number of rows and columns : ");
                scanf("%d%d",&r1,&c1);
                readm(r1,c1,m1);
                printf("\nSecond matrix\n");
                printf("\nEnter the number of rows and columns : ");
                scanf("%d%d",&r2,&c2);
                readm(r2,c2,m2);
                multiplym(r1,c1,r2,c2,m1,m2);
                break;
            case 3:
                printf("\nEnter the number of rows and columns : ");
                scanf("%d%d",&r1,&c1);
                readm(r1,c1,m1);
                transpose(r1,c1,m1);
                break;
            case 4:
                break;
            default:
                printf("Invalid entry.");
        }
        printf("\n");
    }
}