package p2;
import p1.*;
import java.util.*;
import java.io.*;
class CopyPrime
{
	public static void main(String args[]) throws IOException
	{
		int n;
		FileReader fin=new FileReader("data.txt");
		Scanner fscan=new Scanner(fin);
		FileWriter fout=new FileWriter("prime.txt");
		while(fscan.hasNextInt()==true)
		{
			n=fscan.nextInt();
			if(Check.isPrime(n)==true)
			{
				fout.write(Integer.toString(n)+"\n");
			}
		}
		fscan.close();
		fin.close();
		fout.close();
	}
}
