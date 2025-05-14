import java.util.Scanner;

class Employee
{
	int empid;
	String name;
	double salary;
	public void setData(int id,String n,double s)
	{
		empid=id;
		name=n;
		salary=s;
	}
	public void getData()
	{
		System.out.println("Employee id : "+empid+"\nName : "+name+"\nSalary : "+salary);
	}
	public void updateSalary(double s)
	{
		salary=s;
	}
}

class Manager extends Employee
{
	int projectnum;
	public void setData(int id, String n,double s,int pn)
	{
		super.setData(id,n,s);
		projectnum=pn;
	}
	public void getData()
	{
		super.getData();
		System.out.println("Number of projects managed : "+projectnum);
	}
	public void updateProjectNum(int pn)
	{
		projectnum=pn;
	}
}
class SeniorManager extends Manager
{
	double incentive;
	public void setData(int id,String n,double s,int pn,double i)
	{
		super.setData(id,n,s,pn);
		incentive=i;
	}
	public void getData()
	{
		super.getData();
		System.out.println("Incentive : "+incentive);
	}
	public void updateIncentive(double i)
	{
		incentive=i;
	}
}

class Developer extends Employee
{
	String programminglang,projectname;
	public void setData(int id,String n,double s,String pl,String pn)
	{
		super.setData(id,n,s);
		programminglang=pl;
		projectname=pn;
	}
	public void getData()
	{
		super.getData();
		System.out.println("Programming Language : "+programminglang+"\nProject name : "+projectname);
	}
	public void updateProgrammingLang(String n)
	{
		programminglang=n;
	}
	public void updateProjectName(String n)
	{
		projectname=n;
	}
}
class JuniorDeveloper extends Developer
{
	int sysnum;
	public void setData(int id,String n,double s,String pl,String pn,int sys)
	{
		super.setData(id,n,s,pl,pn);
		sysnum=sys;
	}
	public void getData()
	{
		super.getData();
		System.out.println("System number : "+sysnum);
	}
	public void updateSysNum(int n)
	{
		sysnum=n;
	}
}

class Intern extends Employee
{
	int internperiod;
	public void setData(int id,String n,double s,int ip)
	{
		super.setData(id,n,s);
		internperiod=ip;
	}
	public void getData()
	{
		super.getData();
		System.out.println("Internship period : "+internperiod);
	}
	public void updateInternPeriod(int ip)
	{
		internperiod=ip;
	}
}

class EmployeeDemo
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        int c1,c2;
        int id,pnum,projectnum,sysno,pi;
        String n,programminglang,projectname;
        double s,i;
        System.out.println("Vishwanath Pradeep s3 CSE Gamma.");
        do{
            System.out.println("\nChoose the type of Employee:\n1.Manager\n2.Senior Manager\n3.Developer\n4.Junior Developer\n5.Intern\n6.Exit");
            System.out.print("Enter your choice : ");
            c1=scan.nextInt();
            System.out.println();
            if (c1==6)
            {
                break;
            }
            else
            {
                System.out.print("Enter the employee ID : ");
                id=scan.nextInt();
                scan.nextLine();
                System.out.print("Enter the name : ");
                n=scan.nextLine();
                System.out.print("Enter the salary : ");
                s=scan.nextDouble();
            }
            switch(c1)
            {
                case 1:                                                                 //Manager
                    System.out.print("Enter the number of projects : ");
                    pnum=scan.nextInt();
                    Manager m=new Manager();
                    m.setData(id,n,s,pnum);
                    do{
                        System.out.println("\n1.Show Data\n2.Update Salary\n3.Update number of projects\n4.Exit");
                        System.out.print("Enter your choice : ");
                        c2=scan.nextInt();
                        switch(c2)
                        {
                            case 1:
                                m.getData();
                                break;
                            case 2:
                                System.out.print("Enter new salary : ");
                                s=scan.nextDouble();
                                m.updateSalary(s);
                                break;
                            case 3:
                                System.out.print("Enter new number of projects : ");
                                pnum=scan.nextInt();
                                m.updateProjectNum(pnum);
                                break;
                            case 4:
                                break;
                            default:
                                System.out.println("Invalid choice.");
                        }
                    }while(c2!=4);
                    break;
                
                case 2:                                                                 //Senior manager
                    System.out.print("Enter the number of projects : ");
                    pnum=scan.nextInt();
                    System.out.print("Enter the incentive : ");
                    i=scan.nextInt();
                    SeniorManager sm=new SeniorManager();
                    sm.setData(id,n,s,pnum,i);
                    do{
                        System.out.println("\n1.Show Data\n2.Update Salary\n3.Update number of projects\n4.Update incentive\n5.Exit");
                        System.out.print("Enter your choice : ");
                        c2=scan.nextInt();
                        switch(c2)
                        {
                            case 1:
                                sm.getData();
                                break;
                            case 2:
                                System.out.print("Enter new salary : ");
                                s=scan.nextDouble();
                                sm.updateSalary(s);
                                break;
                            case 3:
                                System.out.print("Enter new number of projects : ");
                                pnum=scan.nextInt();
                                sm.updateProjectNum(pnum);
                                break;
                            case 4:
                                System.out.print("Enter new incentive : ");
                                i=scan.nextDouble();
                                sm.updateIncentive(i);
                                break;
                            case 5:
                                break;
                            default:
                                System.out.println("Invalid choice.");
                        }
                    }while(c2!=5);
                    break;
                    
                case 3:                                                                     //Developer
                    scan.nextLine();
                    System.out.print("Enter the programming language : ");
                    programminglang=scan.nextLine();
                    System.out.print("Enter the project name : ");
                    projectname=scan.nextLine();
                    Developer d=new Developer();
                    d.setData(id,n,s,programminglang,projectname);
                    do{
                        System.out.println("\n1.Show Data\n2.Update Salary\n3.Update programming language\n4.Update project name\n5.Exit");
                        System.out.print("Enter your choice : ");
                        c2=scan.nextInt();
                        switch(c2)
                        {
                            case 1:
                                d.getData();
                                break;
                            case 2:
                                System.out.print("Enter new salary : ");
                                s=scan.nextDouble();
                                d.updateSalary(s);
                                break;
                            case 3:
                                scan.nextLine();
                                System.out.print("Enter new programming language : ");
                                programminglang=scan.nextLine();
                                d.updateProgrammingLang(programminglang);
                                break;
                            case 4:
                                scan.nextLine();
                                System.out.print("Enter new project name : ");
                                projectname=scan.nextLine();
                                d.updateProjectName(projectname);
                                break;
                            case 5:
                                break;
                            default:
                                System.out.println("Invalid choice.");
                        }
                    }while(c2!=5);
                    break;
                    
                case 4:                                                                 //Junior developer
                    scan.nextLine();
                    System.out.print("Enter the programming language : ");
                    programminglang=scan.nextLine();
                    System.out.print("Enter the project name : ");
                    projectname=scan.nextLine();
                    System.out.print("Enter the system number : ");
                    sysno=scan.nextInt();
                    JuniorDeveloper jd=new JuniorDeveloper();
                    jd.setData(id,n,s,programminglang,projectname,sysno);
                    do{
                        System.out.println("\n1.Show Data\n2.Update Salary\n3.Update programming language\n4.Update project name\n5.Update System number\n6.Exit");
                        System.out.print("Enter your choice : ");
                        c2=scan.nextInt();
                        switch(c2)
                        {
                            case 1:
                                jd.getData();
                                break;
                            case 2:
                                System.out.print("Enter new salary : ");
                                s=scan.nextDouble();
                                jd.updateSalary(s);
                                break;
                            case 3:
                                scan.nextLine();
                                System.out.print("Enter new programming language : ");
                                programminglang=scan.nextLine();
                                jd.updateProgrammingLang(programminglang);
                                break;
                            case 4:
                                scan.nextLine();
                                System.out.print("Enter new project name : ");
                                projectname=scan.nextLine();
                                jd.updateProjectName(projectname);
                                break;
                            case 5:
                                System.out.print("Enter the new system number : ");
                                sysno=scan.nextInt();
                                jd.updateSysNum(sysno);
                                break;
                            case 6:
                                break;
                            default:
                                System.out.println("Invalid choice.");
                        }
                    }while(c2!=6);
                    break;
                
                case 5:                                                         //Intern
                    System.out.print("Enter internship period : ");
                    pi=scan.nextInt();
                    Intern in=new Intern();
                    in.setData(id,n,s,pi);
                    do{
                        System.out.println("\n1.Show Data\n2.Update Salary\n3.Update internship period\n4.Exit");
                        System.out.print("Enter your choice : ");
                        c2=scan.nextInt();
                        switch(c2)
                        {
                            case 1:
                                in.getData();
                                break;
                            case 2:
                                System.out.print("Enter new salary : ");
                                s=scan.nextDouble();
                                in.updateSalary(s);
                                break;
                            case 3:
                                System.out.print("Enter internship period : ");
                                pi=scan.nextInt();
                                in.updateInternPeriod(pi);
                                break;
                            case 4:
                                break;
                            default:
                                System.out.println("\nInvalid choice.");
                        }
                    }while(c2!=4);
                    break;
                
                case 6:
                    break;

                default:
                    System.out.println("\nInvalid choice. Please try again.");
                    break;
            }
        }while(c1!=6);
    }
}