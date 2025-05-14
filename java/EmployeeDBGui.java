import java.sql.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.event.*;

class EmployeeDBGui extends JFrame implements ActionListener
{
	JLabel heading,empid,name,designation,nationality,joinyear,salary;
	JButton find;
	JTextField empidt,namet,designationt,nationalityt,joinyeart,salaryt,errort;
	
	EmployeeDBGui()
	{
		heading = new JLabel("Employee Details");
		empid = new JLabel("Enter empid :");
		name = new JLabel("Name :");
		designation = new JLabel("Designation :");
		nationality = new JLabel("Nationality :");
		joinyear = new JLabel("Join Year :");
		salary = new JLabel("Salary :");
		
		empidt = new JTextField();
		namet = new JTextField();
		designationt = new JTextField();
		nationalityt = new JTextField();
		joinyeart = new JTextField();
		salaryt = new JTextField();
		errort = new JTextField();

		find = new JButton("Find");

		add(heading);
		add(empid);
		add(name);
		add(designation);
		add(nationality);
		add(joinyear);
		add(salary);
		add(empidt);
		add(namet);
		add(designationt);
		add(nationalityt);
		add(joinyeart);
		add(salaryt);
		add(find);
		add(errort);
		
		setLayout(null);
		setSize(390,270);
		heading.setBounds(140,10,150,20);
		empid.setBounds(10,50,100,20);
		empidt.setBounds(120,50,150,20);
		name.setBounds(10,80,100,20);
		namet.setBounds(120,80,150,20);
		designation.setBounds(10,110,100,20);
		designationt.setBounds(120,110,150,20);
		nationality.setBounds(10,140,100,20);
		nationalityt.setBounds(120,140,150,20);
		joinyear.setBounds(10,170,100,20);
		joinyeart.setBounds(120,170,150,20);
		salary.setBounds(10,200,100,20);
		salaryt.setBounds(120,200,150,20);
		find.setBounds(280,50,100,20);
		errort.setBounds(280,80,100,20);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		find.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{
		Object source = ae.getSource();
		if(source == find)
		{
			errort.setText("");
			int id=Integer.parseInt(empidt.getText());
			try
			{
				int numrows = 0;
				Class.forName("com.mysql.cj.jdbc.Driver");
				Connection con =
				DriverManager.getConnection("jdbc:mysql://localhost:3306/Company","root","root");
				Statement stm = con.createStatement();
				String display = "select * from employees where empid="+id;
				ResultSet rs = stm.executeQuery(display);
				while(rs.next())
				{
					namet.setText(rs.getString(2));
					designationt.setText(rs.getString(3));
					nationalityt.setText(rs.getString(4));
					salaryt.setText(Double.toString(rs.getDouble(6)));
					java.sql.Date date=rs.getDate("year_joining");
					joinyeart.setText(date.toString());
					numrows++;
					break;
				}
				if (numrows == 0)
				{
					errort.setText("Not found");
					namet.setText("");
					designationt.setText("");
					nationalityt.setText("");
					salaryt.setText("");
					joinyeart.setText("");
				}
				rs.close();
				stm.close();
				con.close();
			}
			catch(ClassNotFoundException e){}
			catch(SQLException e){}
		}
	}
	public static void main(String args[])
	{
		EmployeeDBGui obj = new EmployeeDBGui();
	}
}
