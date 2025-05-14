import java.util.*;
class Grade
{
	public static void main(String args[])	
	{
		int m;
		Scanner scan=new Scanner(System.in);
        System.out.println("Vishwanath Pradeep S3 CSE Gamma");
		System.out.print("Enter the marks : ");
		m=scan.nextInt();
		if (m>=90)
			System.out.println("A grade.");
		else if (m>=80)
			System.out.println("B grade.");
		else if (m>=70)
			System.out.println("C grade.");
		else if (m>=60)
			System.out.println("D grade.");
		else if (m>=50)
			System.out.println("E grade.");
		else
			System.out.println("F grade.");
	}
}
