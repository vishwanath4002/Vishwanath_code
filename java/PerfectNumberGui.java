import java.awt.*;
import java.awt.event.*;

public class PerfectNumberGui extends Frame implements ActionListener,WindowListener
{
	Label heading,number,result;
	Button check,clear;
	TextField numtext,res;
	int s=0;
	PerfectNumberGui()
	{
		super("Perfect Number");
		heading = new Label("Check Perfect Number");
		number = new Label("Enter the number :");
		result = new Label("Result :");
				
		check = new Button("Check");
		clear = new Button("Clear");
		
		numtext = new TextField(10);
		res = new TextField(10);
		
		add(heading);
		add(number);
		add(numtext);
		add(check);
		add(result);
		add(res);
		add(clear);

		setLayout(null);
		setSize(400,240);
		heading.setBounds(100,10,100,20);
		number.setBounds(10,50,150,20);
		numtext.setBounds(10,80,300,20);
		result.setBounds(10,110,100,20);
		res.setBounds(10,140,300,20);
		check.setBounds(320,50,70,120);
		clear.setBounds(10,180,380,50);

		setVisible(true);
		check.addActionListener(this);
		clear.addActionListener(this);
		addWindowListener(this);

	}
	
	public boolean checkPerfect(int n)
	{
		s=0;
		for(int i=1;i<n;i++)
		{
			if((n%i) == 0)
			{
				s+=i;
			}
		}
		return (s == n);
	}
	
	public int sumDigits(int n)
	{
		int d,sum=0;
		while(n>0)
		{
			d=n%10;
			sum+=d;
			n/=10;
		}
		return sum;
	}

	public void actionPerformed(ActionEvent ae)
	{
		Object source = ae.getSource();
		int n;
		if(source == check)
		{
			n=Integer.parseInt(numtext.getText());
			if(n<1)
			{
				res.setText("Invalid entry.");
			}
			else if(checkPerfect(n))
			{
				res.setText("It is a perfect number");
			}
			else
			{
				res.setText("It is not a perfect number. Sum of digits is "+sumDigits(n));
			}
		}
		else if(source == clear)
		{
			numtext.setText("");
			res.setText("");
		}
	}
	
	public void windowActivated(WindowEvent e){}    
	public void windowClosed(WindowEvent e){}    
	public void windowClosing(WindowEvent e) 
	{    
		dispose();    
	}    
	public void windowDeactivated(WindowEvent e){}    
	public void windowDeiconified(WindowEvent e){}    
	public void windowIconified(WindowEvent e){}    
	public void windowOpened(WindowEvent e){}    
	    
	public static void main(String args[])
	{
		PerfectNumberGui obj = new PerfectNumberGui();
	}
}
