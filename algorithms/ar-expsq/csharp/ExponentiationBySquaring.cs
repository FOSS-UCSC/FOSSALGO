using System;

public static class ExponentiationBySquaring
{
	public static double exponentiationBySquaring(double base_num, int exponent){
		if(exponent == 0)
		{
			// If the exponent is 0, the answer is always 1
			return 1;
		}
		else if(exponent % 2 == 0)
		{
			/*
			    If the exponent is divisible by 2, recursively call this function,
			    replacing the current exponent, by half of the current exponent,
					and then squaring the result.
			*/
			double value = exponentiationBySquaring(base_num, exponent / 2);
			return value * value;
		}
		else
		{
			/*
			  If the exponent is not divisble by 2, decrement the exponent by 1 and
				recursively call this function, multiplying the result by the given
				base number
			*/
			return base_num * exponentiationBySquaring(base_num, exponent - 1);
		}
	}


	/*
		In the main function, run an example of the exponentiation algorithm
		using 5 ^ 8 (5 to the power of 8)
	*/
	public static void Main()
	{
            var value = exponentiationBySquaring(5, 8);

						if(value > 0)
						{
								// Print the value here
						}
	}

}
