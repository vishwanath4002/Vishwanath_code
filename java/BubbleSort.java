import java.util.*;
class BubbleSort
{
	public static void main(String args[])
	{
		int n,temp;
		int a[]=new int[50];
		Scanner scan=new Scanner(System.in);
		System.out.println("Vishwanath Pradeep Roll no.66");
		System.out.print("Enter the size of the array : ");
		n=scan.nextInt();
		for (int i=0;i<n;i++)
		{
			System.out.print("\nEnter element "+(i+1)+" : ");
			a[i]=scan.nextInt();
		}
		System.out.print("\nThe array is : \t");
		for (int i=0;i<n;i++)
		{
			System.out.print(a[i]+"\t");
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n-i-1;j++)
			{
				if (a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
		}
		System.out.print("\nThe sorted array is : ");
		for (int i=0;i<n;i++)
		{
			System.out.print(a[i]+"\t");
		}
		System.out.println();	
	}
}