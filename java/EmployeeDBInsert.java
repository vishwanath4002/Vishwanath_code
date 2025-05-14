import java.sql.*;
import java.util.*;
class EmployeeDBInsert
{
	public static void main(String args[ ])
	{
		Scanner scan = new Scanner(System.in);
		String empid,name,nationality,designation,date,salary;
		
		System.out.print("Enter the empid : ");
		empid=scan.nextLine();
		System.out.print("Enter the name : ");
		name=scan.nextLine();
		System.out.print("Enter the designation : ");
		designation=scan.nextLine();
		System.out.print("Enter the nationality : ");
		nationality=scan.nextLine();
		System.out.print("Enter the date : ");
		date=scan.nextLine();
		System.out.print("Enter the salary : ");
		salary=scan.nextLine();
		
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con =
			DriverManager.getConnection("jdbc:mysql://localhost:3306/Company","root","root");
			Statement stm = con.createStatement();
			String qry = "insert into employees values("+empid+",'"+name+"','"+designation+"','"+nationality+"','"+date+"',"+salary+")";
			stm.executeUpdate(qry);
			System.out.println("\nRecord inserted.");
			con.close();
			stm.close();
		}
		catch(ClassNotFoundException e)
		{
			System.out.println(e);
		}
		catch(SQLException e)
		{
			System.out.println(e);
		}
	}
}
