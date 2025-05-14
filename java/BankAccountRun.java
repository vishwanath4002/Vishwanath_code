import java.util.*;
class BankAccount
{
	String name;
	int num;
	double balance;
	BankAccount(String na, int n, double b)
	{
		name=na;
		num=n;
		balance=b;
	}
	void getData()
	{
		System.out.println("Customer name : "+name);
		System.out.println("Account number : "+num);
	}
	void checkBalance()
	{
		System.out.println("Balance : "+balance);
	}
	void withdraw(double a)
	{
		if (a>balance)
		{
			System.out.println("Insufficient balance.");
		}
		else
		{
			balance-=a;
		}
		checkBalance();
	}
	void deposit(double a)
	{
		balance+=a;
		checkBalance();
	}
	void updateName(String n)
	{
		name=n;
		System.out.println("Name has been updated.");
	}
}

class BankAccountRun
{
	public static void main(String args[])
	{
		int ch,n;
		String name;
		double a,b;
		Scanner scan=new Scanner(System.in);
        System.out.println("Vishwanath Pradeep S3 CSE Gamma");
		System.out.print("Enter the customer name : ");
		name=scan.nextLine();
		System.out.print("\nEnter the account number : ");
		n=scan.nextInt();
		System.out.print("\nEnter the balance : ");
		b=scan.nextDouble();
        BankAccount b1=new BankAccount(name,n,b);
		do
		{
			System.out.println("\n1.Show customer data\n2.Deposit amount\n3.Withdraw amount\n4.Show balance\n5.Update name\n6.Exit");
			System.out.print("Enter your choice : ");
			ch=scan.nextInt();
			switch(ch)
			{
				case 1:
					b1.getData();
					break;
				case 2:
					System.out.print("\nEnter the amount : ");
					a=scan.nextDouble();
					b1.deposit(a);
					break;
				case 3:
					System.out.print("\nEnter the amount : ");
					a=scan.nextDouble();
					b1.withdraw(a);
					break;
				case 4:
					b1.checkBalance();
					break;
				case 5:
					scan.nextLine();
					System.out.print("\nEnter the new name : ");
					name=scan.nextLine();
					b1.updateName(name);
					break;
				case 6:
					break;
				default:
					System.out.println("Invalid choice.");
			}
		}while (ch!=6);
	}
}