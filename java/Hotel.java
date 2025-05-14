import java.util.*;
import java.io.*;

class RoomAlreadyBookedException extends Exception
{
    public RoomAlreadyBookedException(String s)
    {
        super(s);
    }
}

class HotelFunctions
{
    String rooms[] = {"Luxury Double Room","Double Room","Luxury Single Room","Single Room"};
    public static void available()
    {
        try
        {
            FileReader fin = new FileReader("status.txt");
            Scanner fscan = new Scanner(fin);
            String data;
            data = fscan.nextLine();
            int bookedroom;
            for (int i=0;i<4;i++)
            {
                if (data.indexOf(rooms[i])!=-1)
                {
                    bookedroom = i;
                }
            }
            System.out.println("Available rooms are :");
            for(int i=0,i<4;i++)
            {
                if (i==bookedroom)
                {
                    continue;
                }
                System.out.println(rooms[i]+"\n");
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("All rooms are available.");
        }
        finally
        {
            fscan.close();
            fin.close();
        }
    }

    public static void status()
    {
        try
        {
            FileReader fin = new FileReader("status.txt");
            Scanner fscan = new Scanner(fin);
            String data = fscan.nextLine();
            System.out.println(data);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("No previous status to show.");
        }
        finally
        {
            fin.close();
            fscan.close();
        }
    }

    public static String bookRoom(int r)
    {

    }

    public static void bill(int a[], count)
    {

    }
}

class Hotel
{
    public static void main(String args[])
    {
        int choice, roomchoice, foodchoice;
        int food[] = new int[20];
        String name, roomtype;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the name : ");
        name = scan.nextLine();
        do
        {
            System.out.print("\n1.Show current status\n2.Show available rooms\n3.Book room\n4.Exit\nEnter your choice : ");
            choice=scan.nextInt();
            switch(choice)
            {
                case 1:
                    status();
                    break;
                
                case 2:
                    available();
                    break;
                
                case 3:
                    while(true)
                    {
                        System.out.print("Choose the type of room you want:\n1.Luxury Double room\n2.Double Room\n3.Luxury Single Room\n4.Single Room\n5.Exit\nEnter your choice : ");
                        roomchoice = scan.nextInt();
                        if (roomchoice == 5)
                        {
                            break;
                        }
                        if (roomchoice<1 && roomchoice>5)
                        {
                            System.out.println("Invalid choice. Please try again");
                            continue;
                        }
                        try
                        {
                            roomtype = bookroom(roomchoice);
                            int count = 0;
                            while (true)
                            {
                                System.out.print("Choose the food :\n1.Sandwich Rs.100\n2.Pasta Rs.90\n3.Noodles Rs.80\n4.Coke Rs.30\n5.Show bill\n6.Exit\nEnter your choice : ");
                                if (foodchoice<1 && foodchoice>6)
                                {
                                    System.out.println("Invalid choice. Please try again");
                                    continue;
                                }
                                else if (foodchoice == 6)
                                {
                                    choice = 4;
                                    break;
                                }
                                else if (foodchoice == 5)
                                {
                                    bill(food,count);
                                }
                                else
                                {
                                    foodchoice = scan.nextInt();
                                    food[count] = foodchoice;
                                    count++;
                                }
                            }
                        }
                        catch(RoomAlreadyBookedException e)
                        {
                            System.out.println("Room already booked. Please choose another room.");
                        }
                    }
                    break;

                case 4:
                    break;
                
                default:
                    System.out.println("Invalid choice. Please try again.")
            }

        }while(choice!=4)

        //writing to file
    }
}