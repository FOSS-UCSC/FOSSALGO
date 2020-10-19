// C# program for implementation of KMP pattern searching algorithm 
using System; 

public static class DoKMP { 

	static void LPSArray(string pat, int M, int[] lps) 
	{ 
		// length of the previous longest prefix suffix 
		int len = 0; 
		int i = 1; 
		lps[0] = 0; 

		// the loop calculates lps[i] for i = 1 to M-1 
		while (i < M) { 
			if (pat[i] == pat[len])
			 { 
				len++; 
				lps[i] = len; 
				i++; 
			} 
			else // (pat[i] != pat[len]) 
			{ 
				
				if (len != 0) 
				{ 
					len = lps[len - 1]; 

					
				} 
				else 
				{ 
					lps[i] = len; 
					i++; 
				} 
			} 
		} 
	} 

	static void KMP(string pat, string txt) 
	{ 
		int M = pat.Length; 
		int N = txt.Length; 

		int[] lps = new int[M]; 
		int j = 0; // index for pat[] 

		// Preprocess the pattern (calculate lps[] array) 
			LPSArray(pat, M, lps); 

		int i = 0; // index for txt[] 
		while (i < N) { 
			if (pat[j] == txt[i]) { 
				j++; 
				i++; 
			} 
			if (j == M) { 
				//print (i - j) 
				j = lps[j - 1]; 
			} 

		
			else if (i < N && pat[j] != txt[i]) { 
			
				if (j != 0) 
				{
					j = lps[j - 1]; 
				}
				else
				{
					i = i + 1; 
				}
			} 
		} 
	} 



	// Driver program to test above function 
	public static void Main() 
	{ 
		string txt = "ABABDABACDABABCABAB"; 
		string pat = "ABABCABAB"; 
		KMP(pat, txt); 
	} 
} 


