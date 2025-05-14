import java.util.*;
class Student
{
    int id,disc;
    double cost;
    String cname,sname,lname,bname,subname,pname;
    Student(String coname,int stid,String stname,String brname,String subjname,String lpname,double co,int dis)
    {
        cname=coname;
        id=stid;
        sname=stname;
        bname=brname;
        subname=subjname;
        lname=lpname;
        cost=co;
        disc=dis;
    }
    void getData()
    {
        System.out.println("College name:"+cname+"\nStudent ID:"+id+"\nStudent name:"+sname+"\nBranch name:"+bname+"\nSubject names:"+subname+"\nLearning platform:"+lname+"\nCost per subject:"+cost+"\nDiscount:"+disc);
    }
}
class OnlineStudent extends Student
{
    String appname;
    OnlineStudent(String coname,int stid,String stname,String brname,String subjname,String lpname,double co,int dis)
    {
        super(coname,stid,stname,brname,subjname,lpname,co,dis);
    }
    OnlineStudent(String coname,int stid,String stname,String brname,String subjname,String lpname,double co,int dis,String apn)
    {
        super(coname,stid,stname,brname,subjname,lpname,co,dis);
        appname=apn;
    }
    void getData()
    {
        System.out.println("College name:"+cname+"\nStudent ID:"+id+"\nStudent name:"+sname+"\nBranch name:"+bname+"\nSubject names:"+subname+"\nLearning platform:"+lname+"\nCost per subject:"+cost+"\nDiscount:"+disc+"App name:"+appname);
    }
}
class StudentDemo
{
    public static void main(String args[])
    {
        int ch,ch1,a;
        int id,disc,flag=0;
        double cost;
        String cname,sname,lname,bname,subname,pname,appname;  
        Scanner scan=new Scanner(System.in);
        while(true)
        {
            System.out.println("\n1.Online Student\n2.Exit");
            ch=scan.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.print("Enter ID;");
                    id=scan.nextInt();
                    System.out.print("Enter college name:");
                    cname=scan.nextLine();
                    System.out.print("Enter name:");
                    sname=scan.nextLine();
                    System.out.print("Enter branch name");
                    bname=scan.nextLine();
                    System.out.print("Enter subjects");
                    subname=scan.nextLine();
                    System.out.print("Enter learning platform name");
                    lname=scan.nextLine();
                    System.out.print("Enter cost per subject");
                    cost=scan.nextDouble();
                    System.out.print("Enter discount rate:");
                    disc=scan.nextInt();
                    System.out.println("Do you want to enter add info 1.Yes 2.No");
                    a=scan.nextInt();
                    if(a==1)
                    {
                        System.out.print("Enter app name:");
                        appname=scan.nextLine();
                        flag=1;
                    }
                    do
                    {
                        System.out.println("\n1.Show data\n2.Add info\n3.Exit");
                        ch1=scan.nextInt();
                        switch(ch1)
                        {
                            case 1:
                                if(flag==1)
                                {
                                    OnlineStudent s=new OnlineStudent(cname,id,sname,bname,subname,lname,cost,disc,appname);
                                    s.getData();
                                }
                                Student s1=new Student(cname,id,sname,bname,subname,lname,cost,disc);
                                s1.getData();
                                break;

                            case 2:
                                break;
                            case 3:
                                break;
                            default:
                                System.out.println("Invalid input:");
                                break;
                        }
                    }while(ch1!=3);
                    break;
                
                case 2:
                    System.exit(0);
                    break;
                
                default:
                    System.out.println("Invalid input.");
            }
        }
    }
}
