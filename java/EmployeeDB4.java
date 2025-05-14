import java.sql.*;
import java.io.*;
import java.util.*;
class EmployeeDB4
{
	public static void main(String args[ ])
	{
		Scanner scan = new Scanner(System.in);
		try
		{
			int numrows = 0;
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con =
			DriverManager.getConnection("jdbc:mysql://localhost:3306/Company","root","root");
			Statement stm = con.createStatement();
			
			System.out.println("Existing records : \n");
			String display = "select * from employees";
			ResultSet rs = stm.executeQuery(display);
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
				System.out.println("Empid : "+empid+"\nName : "+name+"\nDesignation : "+designation+"\nNationality : "+nationality+"\nYear of joining : "+rs.getDate(5)+"\nSalary : "+salary+"\n");
				numrows++;
			}
			if(numrows>0)
			{
				System.out.println(numrows+" rows retrieved!");
			}
			else
			{
				System.out.println("Data not found");
			}
			
			int y;
			System.out.print("\nEnter the year : ");
			y=scan.nextInt();
			System.out.println();
			String qry = "delete from employees where YEAR(year_joining)<"+y;
			stm.executeUpdate(qry);
			ResultSet rs2 = stm.executeQuery(display);
			numrows=0;
			while(rs2.next())
			{
				int empid;
				String name,designation,nationality;
				double salary;
				empid=rs2.getInt(1);
				name=rs2.getString(2);
				designation=rs2.getString(3);
				nationality=rs2.getString(4);
				salary=rs2.getDouble(6);
				System.out.println("Empid : "+empid+"\nName : "+name+"\nDesignation : "+designation+"\nNationality : "+nationality+"\nYear of joining : "+rs2.getDate(5)+"\nSalary : "+salary+"\n");
				numrows++;
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
			rs2.close();
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
