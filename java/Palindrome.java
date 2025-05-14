import java.util.*;
class Palindrome
{
	public static void main(String args[])
	{
		int r,n,rev=0;
		Scanner scan=new Scanner(System.in);
		System.out.println("Vishwanath Pradeep Roll no.66");
		System.out.print("\nEnter the number : ");
		n=scan.nextInt();
		for (int i=n;i>0;i/=10)
		{
			r=i%10;
			rev=rev*10+r;
		}
		System.out.println("The reversed number is : "+rev);
		if (rev==n)
		{
			System.out.println(n+" is a palindrome.");
		}
		else
		{
			System.out.println(n+" is not a palindrome.");
		}
	}
}