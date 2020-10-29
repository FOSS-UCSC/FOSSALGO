import java.util.ArrayList;
import java.util.Collections;
/**
 *  Implementation of Longest Palindromic Substring
 *  in Linear Time Complexity using Manachar Algorithm.
 *  @author aayushbest
 */
public class LongestPalindromicSubstring{
	
	/**
	 * <p>Stores the even-length of each palindrome whereas
	 * index will work as center of the palindrome.</p>
	 */
	private static ArrayList<Integer> evenLengthPalindromes;
	
	/**
	 * <p>Stores the odd-length of each palindrome whereas
	 * index will work as center of the palindrome.</p>
	 */
	private static ArrayList<Integer> oddLengthPalindromes;

	/**
	 * Helper methods for the Manacher's algorithm
	 * In order to find max odd length palindrome array.
	 *
	 */
	 private static int getMaxOddPalindrome(final String s){
		 // leftmost index of sub-palindrome
		 int l = 0;
		 // rightmost index of sub-palindrome (maximal)
		 int r = -1;
		 // Calculating longest odd length palindromic substring
		 oddLengthPalindromes = new ArrayList<Integer>();
		 Collections.fill(oddLengthPalindromes, new Integer(0));
		 for(int i = 0; i < s.length(); ++i) {
			 int k = (i > r) ? 1 : Math.min(oddLengthPalindromes.get(l + r - i), r - i + 1);
			 while((0 <= i - k) &&
					 (i + k < s.length()) &&
					 (s.charAt(i - k) == s.charAt(i + k))) {
				 k++;
			 }
			 oddLengthPalindromes.add(i,k--);
			 // if palindrome exceed current boundary
			 // extend those boundaries.
			 if(i + k > r) {
				 l = i - k;
				 r = i + k;
			 }
		 }
		 return Collections.max(oddLengthPalindromes);
	 }
	/**
	 * Helper method to find even length palindrome for Manacher's algorithm
	 */
	 private static int getMaxEvenPalindrome(final String s){
		 // leftmost index of sub-palindrome
		 int l = 0;
		 // rightmost index of sub-palindrome (maximal)
		 int r = -1;
		 // Calculating longest even length palindromic substring
		 evenLengthPalindromes = new ArrayList<Integer>();
		 Collections.fill(evenLengthPalindromes, new Integer(0));
		 for(int i = 0; i < s.length(); ++i) {
			 int k = (i > r) ? 0 : Math.min(evenLengthPalindromes.get(l + r - i + 1),r - i + 1);
			 while((0 <= i - k - 1) &&
					 (i + k < s.length()) &&
					 (s.charAt(i - k - 1) == s.charAt(i + k))){
				 k++;
			 }
			 evenLengthPalindromes.add(i, k--);
			 if(i + k > r) {
				 l = i - k - 1;
				 r = i + k;
			 }
		 }
		return Collections.max(evenLengthPalindromes);
	 }
	/**
	 *  Manacher's Algorithm - Algorithm to find longest palindrome substring
	 *  in O(n) (Linear Time) complexity.
	 */
	public static String longestPalindromicSubstring(final String s) {
		// Longest substring palindrome output
		String result = null;
		// Maximum length of odd palindrome
		int maxOdd = getMaxOddPalindrome(s);
		// Maximum lengtg of even Palindrome
		int maxEven = getMaxEvenPalindrome(s);
		// finding max length index 
		int index = -1;
		if(maxEven>maxOdd) {
			// Getting max index from last if multiple same values possible
			index = evenLengthPalindromes.lastIndexOf(maxEven);
			// Getting substring from [center-length,center+length)
			result = s.substring(index-maxEven,index+maxEven-1);
		}else if(maxEven<=maxOdd) {
			index = oddLengthPalindromes.lastIndexOf(maxOdd);
			result = s.substring(index-maxOdd,index+maxOdd-1);
		}
		return result;
	}
	
	public static void main(String[] args) {
		String test = "abababc";
		String result = longestPalindromicSubstring(test);
		System.out.printf("Given String:%s\nLongest Palindromic Substring:%s",test,result);
	}
}