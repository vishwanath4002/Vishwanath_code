import java.util.*;
import java.io.*;
class CaesarCipher
{
	public static void main(String args[])
	{
		try
		{
			int i,j;
			char c;
			String outputfilename;
			Scanner scan=new Scanner(System.in);
			System.out.print("Enter the name of the output file : ");
			outputfilename=scan.nextLine();		
			FileReader fin=new FileReader("input.txt");
			FileWriter fout=new FileWriter(outputfilename+".txt");
			System.out.println("Contents of input.txt :");
			while((i=fin.read())!=-1)
			{
				c=(char)i;
				System.out.print(c);
				fout.write(i+3);
			}
			fin.close();
			fout.close();
			FileReader efin=new FileReader(outputfilename+".txt");
			System.out.print("\nContents of "+outputfilename+".txt : "+"\n");
			while((j=efin.read())!=-1)
			{
				c=(char)j;
				System.out.write(c);
			}
			System.out.println();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Exception : "+e);
		}
		catch(IOException e)
		{
			System.out.println("Exception : "+e);
		}
	}
}
