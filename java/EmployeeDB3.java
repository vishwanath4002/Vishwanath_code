import java.sql.*;
import java.io.*;
import java.util.*;
class EmployeeDB3
{
	public static void main(String args[ ])
	{
		Scanner scan = new Scanner(System.in);
		try
		{
			int numrows = 0;
			String n,d;
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con =
			DriverManager.getConnection("jdbc:mysql://localhost:3306/Company","root","root");
			Statement stm = con.createStatement();
			String qry = "select * from employees";
			ResultSet rs = stm.executeQuery(qry);
			System.out.print("Enter the required nationality : ");
			n=scan.nextLine();
			System.out.print("\nEnter the required designation : ");
			d=scan.nextLine();
			while(rs.next())
			{
				int empid;
				String name,designation,nationality;
				double salary;
				empid=rs.getInt(1);
				name=rs.getString(2);
				designation=rs.getString(3);
				nationality=rs.getString(4);
				salary=rs.getDouble(6);
				if(nationality.equalsIgnoreCase(n) && designation.equalsIgnoreCase(d))
				{
					System.out.println("Empid : "+empid+"\nName : "+name+"\nDesignation : "+designation+"\nNationality : "+nationality+"\nYear of joining : "+rs.getDate(5)+"\nSalary : "+salary+"\n");
					numrows++;
				}
			}
			if(numrows>0)
			{
				System.out.println(numrows+" rows retrieved!");
			}
			else
			{
				System.out.println("Data not found");
			}
			rs.close();
			stm.close();
			con.close();
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
