// C++ program for implementation of KMP pattern searching algorithm 
#include <bits/stdc++.h> 

// Fills lps[] for given patttern pat[0..M-1] 
void LPSArray(char* pat, int M, int* lps) 
{ 
	
	int len = 0; 

	lps[0] = 0; 


	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			 
			if (len != 0) { 
				len = lps[len - 1]; 

				
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Prints occurrences of txt[] in pat[] 
void KMP(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 


	LPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 



// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCDADBDAABAB"; 	
	char pat[] = "ABABCABAB"; 
	KMP(pat, txt); 
	return 0; 
} 

