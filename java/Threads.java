import java.util.*;
class Display
{
	synchronized void show(int i)
	{
		try
		{
			System.out.println(i);
			Thread.sleep(1500);
			System.out.println(i);
		}
		catch(InterruptedException e)
		{
			System.out.println("Thread Interrupted");
		}
	}
}
class T implements Runnable
{
	Display d = new Display();
	T()
	{
		Thread t1 = new Thread(this);
		Thread t2 = new Thread(this);
		t1.setName("Even");
		t2.setName("Odd");
		t1.start();
		t2.start();
	}
	public void run()
	{
		if((Thread.currentThread().getName()).equals("Even"))
		{
			for(int i=0;i<10;i+=2)
			{
				d.show(i);
			}
		}
		else
		{
			for(int i=1;i<10;i+=2)
			{
				d.show(i);
			}
		}
	}
}
class Threads
{
	public static void main(String args[ ])
	{
		T obj = new T( );
	}
}
