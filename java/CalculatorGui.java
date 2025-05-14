import javax.swing.*;
import java.awt.event.*;
class CalculatorGui extends JFrame implements ActionListener
{
    JLabel heading,s;
    JButton b;
    JTextField num1,num2,res;
    
    CalculatorGui()
    {
        super("Calculator");
        b = new JButton("Add");
        heading = new JLabel("Calculator");
        s = new JLabel("Sum");
        num1 = new JTextField(10);
        num2 = new JTextField(10);
        res = new JTextField(10);
        add(heading);
        add(b);
        add(num1);
        add(num2);
        add(res);
        add(s);

        setLayout(null);
        heading.setBounds(20,10,100,20);
        num1.setBounds(10,40,100,20);
        num2.setBounds(10,70,100,20);
        s.setBounds(10,130,100,20);
        res.setBounds(10,150,100,20);
        b.setBounds(125,10,100,160);

        setSize(250,220);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae)
    {
        Object source = ae.getSource();
        double n1,n2,sum;
        n1=Double.parseDouble(num1.getText());
        n2=Double.parseDouble(num2.getText());
        if(source == b)
        {
            sum=n1+n2;
            res.setText(Double.toString(sum));
        }
    }
    public static void main(String args[])
    {
        CalculatorGui obj=new CalculatorGui();
    }
}