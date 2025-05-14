import javax.swing.*;
import java.awt.event.*;
class GuiCalculator extends JFrame implements ActionListener
{
	JLabel heading,area,length,breadth,base,height,radius,circle,rectangle,triangle;
	JButton ac,ar,at,calc,back;
	JTextField rt,lt,bt,baset,ht,res;
	int s;
	
	GuiCalculator()
	{
		super("Area Calculator");
			heading = new JLabel("Calculator");
			circle = new JLabel("Circle");
			rectangle = new JLabel("Rectangle");
			triangle = new JLabel("Triangle");
			area = new JLabel("Area :");
			length = new JLabel("Length :");
			breadth = new JLabel("Breadth :");			
			base = new JLabel("Base :");
			height = new JLabel("Height :");
			radius = new JLabel("Radius :");
			
			ac = new JButton("Circle");
			ar = new JButton("Rectangle");
			at = new JButton("Triangle");
			calc = new JButton("Calculate");
			back = new JButton("Back");
			
			rt = new JTextField();
			lt = new JTextField();
			bt = new JTextField();
			baset = new JTextField(); 
			ht = new JTextField();
			res = new JTextField();
			
			add(heading);
			add(ac);
			add(ar);
			add(at);
			
			setLayout(null);
			setSize(525,300);
			heading.setBounds(220,10,100,20);
			ac.setBounds(10,50,150,150);
			ar.setBounds(180,50,150,150);
			at.setBounds(350,50,150,150);
			setVisible(true);
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			
			ac.addActionListener(this);
			ar.addActionListener(this);
			at.addActionListener(this);
			calc.addActionListener(this);
			back.addActionListener(this);
	}
	public void home()
	{
		add(heading);
		add(ac);
		add(ar);
		add(at);
		heading.setBounds(220,10,100,20);
		ac.setBounds(10,50,150,150);
		ar.setBounds(180,50,150,150);
		at.setBounds(350,50,150,150);
	}
	public void actionPerformed(ActionEvent ae)
	{
		Object source = ae.getSource();
		double rad,l,br,ba,h,a;
		if(source == ac)
		{
			getContentPane().removeAll();
			s=1;
			add(circle);
			add(radius);
			add(rt);
			add(res);
			add(area);
			add(back);
			add(calc);
			circle.setBounds(220,10,100,20);
			radius.setBounds(10,50,100,20);
			rt.setBounds(120,50,250,20);
			area.setBounds(10,150,100,20);
			res.setBounds(120,150,250,20);
			calc.setBounds(400,50,100,120);
			back.setBounds(10,200,490,50);
			repaint();
		}
		else if(source == ar)
		{
			s=2;
			getContentPane().removeAll();
			add(rectangle);
			add(length);
			add(breadth);
			add(lt);
			add(bt);
			add(area);
			add(res);
			add(back);
			add(calc);
			rectangle.setBounds(220,10,100,20);
			length.setBounds(10,50,100,20);
			lt.setBounds(120,50,250,20);
			breadth.setBounds(10,100,100,20);
			bt.setBounds(120,100,250,20);
			area.setBounds(10,150,100,20);
			res.setBounds(120,150,250,20);
			calc.setBounds(400,50,100,120);
			back.setBounds(10,200,490,50);
			repaint();
		}
		else if(source == at)
		{
			s=3;
			getContentPane().removeAll();
			add(triangle);
			add(base);
			add(height);
			add(baset);
			add(ht);
			add(area);
			add(res);
			add(back);
			add(calc);
			triangle.setBounds(220,10,100,20);
			base.setBounds(10,50,100,20);
			baset.setBounds(120,50,250,20);
			height.setBounds(10,100,100,20);
			ht.setBounds(120,100,250,20);
			area.setBounds(10,150,100,20);
			res.setBounds(120,150,250,20);
			calc.setBounds(400,50,100,120);
			back.setBounds(10,200,490,50);
			repaint();
		}
		else if(source == back)
		{
			res.setText("");
			rt.setText("");
			lt.setText("");
			bt.setText("");
			baset.setText("");
			ht.setText("");
			getContentPane().removeAll();
			home();
			revalidate();
			repaint();
		}
		else if(source == calc)
		{
			if(s == 1)
			{
				rad=Double.parseDouble(rt.getText());
				a=3.14*rad*rad;
				res.setText(Double.toString(a));
			}
			else if(s == 2)
			{
				l=Double.parseDouble(lt.getText());
				br=Double.parseDouble(bt.getText());
				a=l*br;
				res.setText(Double.toString(a));
			}
			else if(s == 3)
			{
				ba=Double.parseDouble(baset.getText());
				h=Double.parseDouble(ht.getText());
				a=0.5*ba*h;
				res.setText(Double.toString(a));
			}
		}
	}
	public static void main(String args[])
	{
		GuiCalculator obj = new GuiCalculator();
	}
}
