import java.util.*;
class OddEvenCount
{
	public static void main(String args[])
	{
		int n,co=0,ce=0;
		int a[]=new int[50];
		Scanner scan=new Scanner(System.in);
		System.out.println("Vishwanath Pradeep Roll no.66");
		System.out.print("Enter the size of array : ");
		n=scan.nextInt();
		for (int i=0;i<n;i++)
		{
			System.out.print("\nEnter element "+(i+1)+" : ");
			a[i]=scan.nextInt();
		}
		for (int i=0;i<n;i++)
		{
			if (a[i]%2==0)
			{
				ce++;
			}
			else
			{
				co++;
			}
		}
		System.out.println("\nCount of even numbers : "+ce+"\nCount of odd numbers : "+co);
	}
}