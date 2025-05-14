import java.util.*;
class LinearSearch
{
	public static void main(String args[])
	{
		int n,e,f=-1;
		int a[]=new int[50];
		Scanner scan=new Scanner(System.in);
		System.out.println("Vishwanath Pradeep Roll no 66");
		System.out.print("Enter the size of array : ");
		n=scan.nextInt();
		for (int i=0;i<n;i++)
		{
			System.out.print("\nEnter element "+(i+1)+" : ");
			a[i]=scan.nextInt();
		}
		System.out.print("\nEnter the element to be searched : ");
		e=scan.nextInt();
		for (int i=0;i<n;i++)
		{
			if (e==a[i])
			{
				System.out.println("Element found at index "+i+".");
				f=1;
				break;
			}
		}
		if (f==-1)
		{
			System.out.println("Element not found.");
		}
		
	}
}