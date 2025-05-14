#include <stdio.h>
int m1[10][10], m2[10][10],s1[10][3],s2[10][3],sum[10][3];
void readm(int r,int c,int m[10][10])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("\nEnter element at %d,%d : ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}
void sparseconversion(int a[10][10], int s[10][3],int r,int c)
{
    s[0][0]=r;
    s[0][1]=c;
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                k++;
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
            }
        }
    }
    s[0][2]=k;
}
void add(int a[10][3], int b[10][3])
{
    int i=1,j=1,k=1;
    sum[0][0]=a[0][0];
    sum[0][1]=a[0][1];
    while (i<=a[0][2]&&j<=b[0][2])
    {
        if(a[i][0]>b[j][0])
        {
            sum[k][0]=a[i][0];
            sum[k][1]=a[i][1];
            sum[k][2]=a[i][2];
            i++;
            k++;
        }
        else if (a[i][0]<b[j][0])
        {
            sum[k][0]=b[j][0];
            sum[k][1]=b[j][1];
            sum[k][2]=b[j][2];
            j++;
            k++;
        }
        else if (a[i][0]=b[j][0])
        {
            if(a[i][1]<b[j][1])
            {
                sum[k][0]=b[j][0];
                sum[k][1]=b[j][1];
                sum[k][2]=b[j][2];
                j++;
                k++;   
            }
            else if(a[i][1]>b[j][1])
            {
                sum[k][0]=a[i][0];
                sum[k][1]=a[i][1];
                sum[k][2]=a[i][2];
                i++;
                k++;
            }
            else
            {
                sum[k][0]=a[i][0];
                sum[k][1]=a[i][1];
                sum[k][2]=a[i][2]+b[j][2];
                i++;
                j++;
                k++;
            }
        }
    }
}
void display(int s[10][3])
{
    for(int i=0;i<=s[0][2];i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
}
void transpose()
{
    int i=1,j=1,a=0,t=1;
    s2[0][0]=s1[0][1];
    s2[0][1]=s1[0][0];
    s2[0][2]=s1[0][2];
    while(t<=s1[0][2])
    {
        while(i<=s1[0][2])
        {
            if (s1[i][1]==a)
            {
                s2[t][0]=s1[i][1];
                s2[t][1]=s1[i][0];
                s2[t][2]=s1[i][2];
                t++,i++,a++;
            }
        }
    }
}
void main()
{
    int r,c,ch=0;
    while(ch!=3)
    {
        printf("1.Sparse matrix addition\n2.Transpose\n3.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of rows and columns : ");
                scanf("%d%d",&r,&c);
                printf("\nMatrix 1 :\n");
                readm(r,c,m1);
                printf("\nMatrix 2 :\n");
                readm(r,c,m2);
                sparseconversion(m1,s1,r,c);
                sparseconversion(m2,s2,r,c);
                add(s1,s2);
                display(sum);
                break;
            
            case 2:
                printf("Enter the number of rows and columns : ");
                scanf("%d%d",&r,&c);
                printf("\nMatrix :\n");
                readm(r,c,m1);
                sparseconversion(m1,s1,r,c);
                transpose();
                display(s2);
                break;
            
            case 3:
                break;
            
            default:
                printf("Invalid entry.");
        }
    }
}