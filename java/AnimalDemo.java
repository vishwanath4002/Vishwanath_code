import java.util.*;

class Animal
{
    String name;
    int age;
    Scanner scan=new Scanner(System.in);
    Animal(String n,int a)
    {
        name=n;
        age=a;
    }
    public void move()
    {
        System.out.println(name+" is moving.");
    }
    public void stopMoving()
    {
        System.out.println(name+" has stopped moving.");
    }
}
class Mammal extends Animal
{
    int gp;
    String type;
    Scanner scan=new Scanner(System.in);
    Mammal(String n,int a,int g,String t)
    {
        super(n,a);
        gp=g;
        type=t;
    }
    void giveBirth()
    {
        System.out.println(name+" has given birth.");
    }
    void sleep()
    {
        System.out.println(name+" fell asleep.");
    }
}
class NonMammal extends Animal
{
    int incubation_period;
    Scanner scan=new Scanner(System.in);
    NonMammal(String n,int a,int i)
    {
        super(n,a);
        incubation_period=i;
    }
    void layEggs()
    {
        System.out.println(name+" laid eggs.");
    }
    void sleep()
    {
        System.out.println(name+" fell asleep.");
    }
}
class AnimalDemo
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        int ch1,ch2=0;
        String n,t;
        int a,g,i;
        System.out.print("Choose the type of animal.\n1.Mammal\n2.Non Mammal\nEnter your choice : ");
        ch1=scan.nextInt();
        switch(ch1)
        {
            case 1:
                scan.nextLine();
                System.out.print("Enter the name : ");
                n=scan.nextLine();
                System.out.print("\nEnter the age : ");
                a=scan.nextInt();
                System.out.print("Enter the Gestation period : ");
                g=scan.nextInt();
                scan.nextLine();
                System.out.print("\nEnter the type (herbivore,carnivore,omnivore) : ");
                t=scan.nextLine();
                Mammal m=new Mammal(n,a,g,t);
                while(ch2!=5)
                {
                    System.out.print("\nChoose activity:\n1.Move\n2.Stop moving\n3.Give birth\n4.Sleep\n5.Exit\nEnter your choice : ");
                    ch2=scan.nextInt();
                    switch(ch2)
                    {
                        case 1:
                            m.move();
                            break;
                        case 2:
                            m.stopMoving();
                            break;
                        case 3:
                            m.giveBirth();
                            break;
                        case 4:
                            m.sleep();
                            break;
                        case 5:
                            break;
                        default:
                            System.out.println("Invalid choice.");
                    }
                }
                break;
                
            case 2:
                scan.nextLine();
                System.out.print("Enter the name : ");
                n=scan.nextLine();
                System.out.print("\nEnter the age : ");
                a=scan.nextInt();
                System.out.print("Enter the incubation period : ");
                i=scan.nextInt();
                NonMammal nm=new NonMammal(n,a,i);
                while(ch2!=5)
                {
                    System.out.print("\nChoose activity:\n1.Move\n2.Stop Moving\n3.Lay Eggs\n4.Sleep\n5.Exit\nEnter your choice : ");
                    ch2=scan.nextInt();
                    switch(ch2)
                    {
                        case 1:
                            nm.move();
                            break;
                        case 2:
                            nm.stopMoving();
                            break;
                        case 3:
                            nm.layEggs();
                            break;
                        case 4:
                            nm.sleep();
                            break;
                        case 5:
                            break;
                        default:
                            System.out.println("Invalid choice.");
                    }
                }
                break;
                
            default:
                System.out.println("Invalid choice.");
        }
    }
}