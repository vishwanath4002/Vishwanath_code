import javax.swing.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
class ATMGui extends JFrame implements ActionListener
{
    JLabel sbi,acc,newbalance, balance, amount, toacc;
    JTextField acct,accerrort,newacct,newbalancet,createt,balancet,amountt,messaget,toacct,tamountt,transfermessaget;
    JButton login,createscreen,back,create,clear,logout,withdraw,deposit,transferscreen,transfer;
    int s=0;
    double b,a;
    String accnum;

    ATMGui()
    {
        sbi = new JLabel("State Bank of India");
        acc = new JLabel("Enter acc num : ");
        newbalance = new JLabel("Enter balance : ");
        balance = new JLabel("Balance : ");
        amount = new JLabel("Enter Amount : ");
        toacc = new JLabel("Acc num : ");

        acct = new JTextField(20);
        accerrort = new JTextField(20);
        newacct = new JTextField(20);
        newbalancet = new JTextField(20);
        createt = new JTextField(20);
        balancet = new JTextField(20);
        amountt = new JTextField(20);
        messaget = new JTextField(20);
        toacct = new JTextField(20);
        tamountt = new JTextField(20);
        transfermessaget = new JTextField(20);

        login = new JButton("Login");
        createscreen = new JButton("Create account");
        back = new JButton("Back");
        create = new JButton("Create");
        clear = new JButton("Clear");
        logout = new JButton("Logout");
        withdraw = new JButton("Withdraw");
        deposit = new JButton("Deposit");
        transferscreen = new JButton("Transfer");
        transfer = new JButton("Transfer");

        add(sbi);
        add(acc);
        add(acct);
        add(accerrort);
        add(login);
        add(createscreen);

        setLayout(null);
        setSize(415,305);
        sbi.setBounds(150,10,200,30);
        acc.setBounds(10,100,100,20);
        acct.setBounds(130,100,110,20);
        accerrort.setBounds(130,150,110,20);
        login.setBounds(250,100,140,20);
        createscreen.setBounds(250,150,140,20);
        setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

        login.addActionListener(this);
        createscreen.addActionListener(this);
        back.addActionListener(this);
        create.addActionListener(this);
        clear.addActionListener(this);
        logout.addActionListener(this);
        withdraw.addActionListener(this);
        deposit.addActionListener(this);
        transferscreen.addActionListener(this);
        transfer.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae)
    {
        Object source = ae.getSource();

        if (source == createscreen)
        {
            getContentPane().removeAll();
            s=1;
            add(back);
            add(acc);
            add(newacct);
            add(balance);
            add(newbalancet);
            add(create);
            add(createt);
            add(clear);

            back.setBounds(10,10,80,30);
            acc.setBounds(10,50,100,20);
            newacct.setBounds(130,50,150,20);
            balance.setBounds(10,100,100,20);
            newbalancet.setBounds(130,100,150,20);
            create.setBounds(300,50,80,70);
            createt.setBounds(130,150,150,20);
            clear.setBounds(300,150,80,20);

            acct.setText("");
            accerrort.setText("");
            repaint();
        }

        else if (source == create)
        {
            try
            {
                String newaccnum = newacct.getText();
                FileWriter fout = new FileWriter(newaccnum+".txt");
                fout.write(newbalancet.getText());
                createt.setText("Account created.");
                fout.close();
            }
            catch(IOException e){}
        }

        else if (source == clear)
        {
            if (s == 1)
            {
                newacct.setText("");
                newbalancet.setText("");
                createt.setText("");
            }
            else if (s == 2)
            {
                amountt.setText("");
                messaget.setText("");
            }
        }

        else if (source == back)
        {
            if (s==1)
            {
                getContentPane().removeAll();
                s=0;
                add(sbi);
                add(acc);
                add(acct);
                add(accerrort);
                add(login);
                add(createscreen);

                sbi.setBounds(150,10,200,30);
                acc.setBounds(10,100,100,20);
                acct.setBounds(130,100,110,20);
                accerrort.setBounds(130,150,110,20);
                login.setBounds(250,100,140,20);
                createscreen.setBounds(250,150,140,20);
                repaint();
            }
            else if (s==3)
            {
                getContentPane().removeAll();
                s=2;
                add(balance);
                add(balancet);
                add(logout);
                add(amount);
                add(amountt);
                add(clear);
                add(withdraw);
                add(deposit);
                add(transferscreen);
                add(messaget);
                
                balance.setBounds(10,10,100,20);
                balancet.setBounds(130,10,100,20);
                logout.setBounds(290,10,100,20);
                amount.setBounds(10,50,100,20);
                amountt.setBounds(130,50,100,20);
                clear.setBounds(290,50,100,20);
                withdraw.setBounds(10,100,120,120);
                deposit.setBounds(140,100,120,120);
                transferscreen.setBounds(270,100,120,120);
                messaget.setBounds(10,230,380,30);

                balancet.setText(Double.toString(b));
                transfermessaget.setText("");
                toacct.setText("");
                tamountt.setText("");
                repaint();
            }
        }
        else if (source == login)
        {
            accnum=acct.getText();
            try
            {
                FileReader fin = new FileReader(accnum+".txt");
                Scanner fscan = new Scanner(fin);
                b=fscan.nextDouble();
                fin.close();
                fscan.close();
                getContentPane().removeAll();
                s=2;
                add(balance);
                add(balancet);
                add(logout);
                add(amount);
                add(amountt);
                add(clear);
                add(withdraw);
                add(deposit);
                add(transferscreen);
                add(messaget);
                
                balance.setBounds(10,10,100,20);
                balancet.setBounds(130,10,100,20);
                logout.setBounds(290,10,100,20);
                amount.setBounds(10,50,100,20);
                amountt.setBounds(130,50,100,20);
                clear.setBounds(290,50,100,20);
                withdraw.setBounds(10,100,120,120);
                deposit.setBounds(140,100,120,120);
                transferscreen.setBounds(270,100,120,120);
                messaget.setBounds(10,230,380,30);

                balancet.setText(Double.toString(b));
                acct.setText("");
                accerrort.setText("");
                repaint();
            }
            catch(FileNotFoundException e)
            {
                accerrort.setText("Account not found");
            }
            catch(IOException e){}
        }
        else if (source == logout)
        {
            getContentPane().removeAll();
            s=0;
            add(sbi);
            add(acc);
            add(acct);
            add(accerrort);
            add(login);
            add(createscreen);

            sbi.setBounds(150,10,200,30);
            acc.setBounds(10,100,100,20);
            acct.setBounds(130,100,110,20);
            accerrort.setBounds(130,150,110,20);
            login.setBounds(250,100,140,20);
            createscreen.setBounds(250,150,140,20);
            repaint();
        }

        else if (source == withdraw)
        {
            try
            {
                a=Double.parseDouble(amountt.getText());
                if (a>b)
                {
                    throw new ArithmeticException("Insufficient Balance");
                }
                b-=a;
                FileWriter fout = new FileWriter(accnum+".txt");
                fout.write(Double.toString(b));
                fout.close();
                balancet.setText(Double.toString(b));
                messaget.setText("Amount withdrawn");
            }
            catch(ArithmeticException e)
            {
                messaget.setText("Insufficient balance.");
            }
            catch(IOException e){}
        }

        else if (source == deposit)
        {
            try
            {
                a=Double.parseDouble(amountt.getText());
                b+=a;
                FileWriter fout = new FileWriter(accnum+".txt");
                fout.write(Double.toString(b));
                fout.close();
                balancet.setText(Double.toString(b));
                messaget.setText("Amount deposited");
            }
            catch(IOException e){}
        }

        else if (source == transferscreen)
        {
            getContentPane().removeAll();
            s=3;
            add(back);
            add(toacc);
            add(toacct);
            add(amount);
            add(tamountt);
            add(transfer);
            add(transfermessaget);
            
            back.setBounds(10,10,80,30);
            toacc.setBounds(10,100,100,20);
            toacct.setBounds(130,100,150,20);
            amount.setBounds(10,150,100,20);
            tamountt.setBounds(130,150,150,20);
            transfer.setBounds(300,100,90,70);
            transfermessaget.setBounds(130,200,150,20);
            repaint();
        }

        else if (source == transfer)
        {
            String toaccnum=toacct.getText();
            a=Double.parseDouble(tamountt.getText());
            double tb;
            try
            {
                FileReader fin = new FileReader(toaccnum+".txt");
                Scanner fscan = new Scanner(fin);
                tb=fscan.nextDouble();
                if (a>b)
                {
                    throw new ArithmeticException("Insufficient Balance.");
                }
                tb+=a;
                b-=a;
                fin.close();
                fscan.close();
                FileWriter foutf = new FileWriter(accnum+".txt");
                foutf.write(Double.toString(b));
                FileWriter fout = new FileWriter(toaccnum+".txt");
                fout.write(Double.toString(tb));
                transfermessaget.setText("Amount transferred.");
                foutf.close();
                fout.close();
            }
            catch(ArithmeticException e)
            {
                transfermessaget.setText("Insufficient Balance.");
            }
            catch(FileNotFoundException e)
            {
                transfermessaget.setText("Account not found.");
            }
            catch(IOException e){}
        }
    }
    public static void main(String args[])
    {
        ATMGui obj = new ATMGui();
    }
} 