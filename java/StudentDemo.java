import java.util.*;
class Student
{
	String name;
	int rollno;
	double mark1,mark2;
	static int count;
	Student()
	{
		count++;
	}
	void setData(String n,int r,double m1, double m2)
	{
		name=n;
		rollno=r;
		mark1=m1;
		mark2=m2;
	}
	void getData()
	{
		System.out.println("Name : "+name);
		System.out.println("Roll no. : "+rollno);
		System.out.println("Marks of first subject : "+mark1);
		System.out.println("Marks of second subject : "+mark2);
	}
	void getTotal()
	{
		double total;
		total=mark1+mark2;
		System.out.println("Total marks is : "+total);
	}	
	static void getCount()
	{
		System.out.println("Count of students is : "+count);
	}
	protected void finalize()
	{
		count--;
	}
}
class StudentDemo
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		String n;
		int r,c;
		double m1,m2;
		System.out.println("Vishwanath Pradeep s3 CSE Gamma.\n");
		System.out.println("Enter details of students :\nStudent 1:");
		System.out.print("Enter the name : ");
		n=scan.nextLine();
		System.out.print("Enter the roll number : ");
		r=scan.nextInt();
		System.out.print("Enter the marks of both subjects : ");
		m1=scan.nextInt();
		m2=scan.nextInt();
		Student s1=new Student();
		s1.setData(n,r,m1,m2);
		System.out.println("\nStudent 2:");
		scan.nextLine();
		System.out.print("Enter the name : ");
		n=scan.nextLine();
		System.out.print("Enter the roll number : ");
		r=scan.nextInt();
		System.out.print("Enter the marks of both subjects : ");
		m1=scan.nextInt();
		m2=scan.nextInt();
		Student s2=new Student();
		s2.setData(n,r,m1,m2);
		System.out.println("\nDetails of both students :\nStudent 1:");
		s1.getData();
		s1.getTotal();
		System.out.println("Student 2:");
		s2.getData();
		s2.getTotal();
		System.out.println();
		Student.getCount();
		System.out.print("\nWhich student should be removed, 1 or 2?\nEnter your choice : ");
		c=scan.nextInt();
		if (c==1)
		{
			s1=null;
		}
		else if (c==2)
		{
			s2=null;
		}
		else
		{
			System.out.println("Invalid choice.");
		}
		System.gc();
		System.runFinalization();
		Student.getCount();
	}
}
