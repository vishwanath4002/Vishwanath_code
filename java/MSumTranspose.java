import java.util.*;
class Matrix
{
    Scanner scan=new Scanner(System.in);
    void readM(int m[][],int r, int c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print("Enter element at "+i+","+j+" : ");
                m[i][j]=scan.nextInt();
            }
        }
    }
    void displayM(int m[][],int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print(m[i][j]+"\t");
            }
            System.out.println();
        }
    }
}
class MSumTranspose
{
    public static void main(String args[])
    {
        int r,c;
        int m1[][]=new int[10][10];
        int m2[][]=new int[10][10];
        int s[][]=new int[10][10];
        int t[][]=new int[10][10];
        Scanner scan=new Scanner(System.in);
        Matrix m=new Matrix();
        System.out.println("Vishwanath Pradeep S3 CSE Gamma");
        System.out.print("Enter the number of rows and columns : ");
        r=scan.nextInt();
        c=scan.nextInt();
        System.out.println("Matrix 1:");
        m.readM(m1,r,c);
        System.out.println("\nMatrix 2:");
        m.readM(m2,r,c);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                s[i][j]=m1[i][j]+m2[i][j];
            }
        }
        System.out.println("Sum is :");
        m.displayM(s,r,c);
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                t[i][j]=s[j][i];
            }
        }
        System.out.println("Transpose of sum is :");
        m.displayM(t,c,r);
    }
}