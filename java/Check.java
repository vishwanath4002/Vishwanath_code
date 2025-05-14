package p1;
public class Check
{
	public static boolean isPrime(int n)
	{
		int f=0;
		if(n==0||n==1)
		{
			return false;
		}
		for(int i=1;i<=n/2;i++)
		{
			if(n%i==0)
			{
				f++;
			}
			if(f>1)
			{
				return false;
			}
		}
		return true;
	}
}
