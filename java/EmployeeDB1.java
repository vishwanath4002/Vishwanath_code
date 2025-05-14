import java.sql.*;
import java.io.*;
class EmployeeDB1
{
	public static void main(String args[ ])
	{
		PrintWriter pw = new PrintWriter(System.out,true);
		try
		{
			int numrows = 0;
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con =
			DriverManager.getConnection("jdbc:mysql://localhost:3306/Company","root","root");
			Statement stm = con.createStatement();
			String qry = "select * from employees order by salary desc";
			ResultSet rs = stm.executeQuery(qry);
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
				pw.println("Empid : "+empid+"\nName : "+name+"\nDesignation : "+designation+"\nNationality : "+nationality+"\nYear of joining : "+rs.getDate(5)+"\nSalary : "+salary+"\n");
				numrows++;
			}
			if(numrows>0)
			{
				pw.println(numrows+" rows retrieved!");
			}
			else
			{
				pw.println("Data not found");
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
