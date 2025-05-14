import java.util.*;
class MenuCalc
{
	public static void main(String args[])
	{
		int c;
		double a,b,r;
		Scanner scan=new Scanner(System.in);
        System.out.println("Vishwanath Pradeep S3 CSE Gamma.");
		do
		{
			System.out.print("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\nEnter your choice : ");
			c=scan.nextInt();
			switch(c)
			{
				case 1:
					System.out.print("Enter the numbers : ");
					a=scan.nextDouble();
					b=scan.nextDouble();
					r=a+b;
					System.out.println("\n"+a+" + "+b+" = "+r);
					break;
				case 2:
					System.out.print("Enter the numbers : ");
					a=scan.nextDouble();
					b=scan.nextDouble();
					r=a-b;
					System.out.println("\n"+a+" - "+b+" = "+r);
					break;
				case 3:
					System.out.print("Enter the numbers : ");
					a=scan.nextDouble();
					b=scan.nextDouble();
					r=a*b;
					System.out.println("\n"+a+" * "+b+" = "+r);
					break;
				case 4:
					System.out.print("Enter the numbers : ");
					a=scan.nextDouble();
					b=scan.nextDouble();
                    if(b==0)
                    {
                        System.out.println("Division by zero is not possible.");
                    }
                    else
                    {
                        r=a/b;
					    System.out.println("\n"+a+" / "+b+" = "+r);
                    }
					break;
				case 5:
					System.exit(0);
                    break;
                default:
                    System.out.println("Invalid entry.");
			}
		}while(true);
	}
}