#include <stdio.h>

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

void displaym(int a, int b,int m[a][b])
{
    printf("\n");
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }    
}

void addm()
{
    int r1,r2,c1,c2;
    printf("\nEnter the number of rows and columns of the first matrix : ");
    scanf("%d%d",&r1,&c1);
    int m1[r1][c1];
    readm(r1,c1,m1);

    printf("\nEnter the number of rows and columns of the second matrix : ");
    scanf("%d%d",&r2,&c2);
    int m2[r2][c2];
    readm(r2,c2,m2);
    printf("\n");
    if (r1==r2 && c1==c2)
    {
        int sum[r1][c1];
        for (int i=0;i<r1;i++)
        {
            for (int j=0;j<c1;j++)
            {
                sum[i][j]=m1[i][j]+m2[i][j];
            }
        }
        printf("The sum is : \n");
        displaym(r1,c1,sum);
    }
    else
        printf("The orders of the matrices are incompatible for addition.");

}

void multiplym()
{
    int r1,r2,c1,c2;
    printf("\nEnter the number of rows and columns of the first matrix : ");
    scanf("%d%d",&r1,&c1);
    int m1[r1][c1];
    readm(r1,c1,m1);

    printf("\nEnter the number of rows and columns of the second matrix : ");
    scanf("%d%d",&r2,&c2);
    int m2[r2][c2];
    readm(r2,c2,m2);
    printf("\n");

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
                    s+=m1[r][i]*m2[i][c];
                }
                p[r][c]=s;
            }
        }
        displaym(r1,c2,p);
    }
    else
        printf("The orders of the matrices are incompatible for multiplication.");
}

void transpose()
{
    int r,c;
    printf("\nEnter the number of rows and columns of the first matrix : ");
    scanf("%d%d",&r,&c);
    int m[r][c];
    readm(r,c,m);
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
    int c;
    while (c!=4)
    {
        printf("__________________________");
        printf("\n1.Matrix addition\n2.Matrix multiplication.\n3.Transpose.\n4.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                addm();
                break;
            case 2:
                multiplym();
                break;
            case 3:
                transpose();
                break;
            case 4:
                break;
            default:
                printf("Invalid entry.");
        }
        printf("\n");
    }
}