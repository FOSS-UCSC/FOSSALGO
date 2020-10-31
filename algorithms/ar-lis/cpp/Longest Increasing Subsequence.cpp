#include<bits/stdc++.h> 
using namespace std; 

int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
	if (v.size() == 0) 
		return 0; 

	std::vector<int> tail(v.size(), 0); 
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0]; 
	
	for (int i = 1; i < v.size(); i++) { 

			// Do binary search for the element in 
			// the range from begin to begin + length 
		auto b = tail.begin(), e = tail.begin() + length; 
		auto it = lower_bound(b, e, v[i]); 
			
		// If not present change the tail element to v[i] 
		if (it == tail.begin() + length) 
		tail[length++] = v[i]; 
		else
		*it = v[i]; 
	} 

	return length; 
} 

int main() 
{ 
	std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
	std::cout << "Length of Longest Increasing Subsequence is "
			<< LongestIncreasingSubsequenceLength(v); 
	return 0; 
} 
