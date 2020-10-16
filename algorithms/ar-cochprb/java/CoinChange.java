import java.util.Scanner;
class CoinChange
{
	
	public static int coinChange(int[] coin, int N)
	{
		
		if (N == 0) {
			return 1;
		}

		
		if (N < 0) {
			return 0;
		}

		
		int res = 0;

		
		for (int i = 0; i < coin.length; i++)
		{
			
			res += coinChange(coin, N - coin[i]);
		}

		
		return res;
	}

	public static void main(String[] args)
	{   Scanner sc = new Scanner(System.in);
         
        System.out.println("Enter the no. of coin denominations");
        int n=sc.nextInt();
        int[] coin = new int[n]; 
        for(int i=0;i<n;i++)
        {    System.out.println("Enter the denomination value");
            coin[i]=sc.nextInt();
        }

		
		System.out.println("Enter the Target Coin Sum");
		int N = sc.nextInt();

		System.out.println("Total number of ways to get desired change is "
				+ coinChange(coin, N));
	}
}