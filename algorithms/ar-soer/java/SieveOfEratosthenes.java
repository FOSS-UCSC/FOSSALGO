//Sieve of Eratosthenes


class SieveOfEratosthenes 
{ 
	void sieveOfEratosthenes(int number) 
	{ 
		
		boolean prime[] = new boolean[number+1]; 
		for(int preSet=0;preSet<number;preSet++) 
			prime[preSet] = true; 
		
		for(int checkNo = 2; checkNo*checkNo <=number; checkNo++) 
		{ 
			
			if(prime[checkNo] == true) 
			{ 
				
				for(int mul = checkNo*checkNo; mul <= number; mul += checkNo) 
					prime[mul] = false; 
			} 
		} 
		
		
		for(int primeNum = 2;primeNum <= number; primeNum++) 
		{ 
			if(prime[primeNum] == true) 
				System.out.print(primeNum + " "); 
		} 
	} 
	
	
	public static void main(String args[]) 
	{ 
		int number = 20; 
		System.out.print(" Prime numbers "); 
		System.out.println("smaller than or equal to " + number); 
		SieveOfEratosthenes g = new SieveOfEratosthenes(); 
		g.sieveOfEratosthenes(number); 
	} 
} 


