#include<bits/stdc++.h>
using namespace std;
/*
Input Format:
The first and the only argument contains an integer array, A.

Output Format:
Return an integer representing the maximum possible sum of the contiguous subarray.
*/
int maxSumSubArray(const vector<int> &A) {
    int l=A.size();
    int curmax=A[0];
    int ans=A[0];
    int s=0;
    for(int i=1;i<l;i++)
    {
        curmax=max(curmax+A[i],A[i]);
        ans=max(curmax,ans);
    }
    return ans;
}
//driver function
int main()
{
    vector<int>v;
    int n;
    cin>>n; //enter size of vector
    for(int i=0;i<n;i++)
    {
        int s;
        cin>>s;
        v.push_back(s);
    }
    cout<<maxSumSubArray(v)<<"\n";
    return 0;
}
/*
input output example:
Input 1:
    A = [1, 2, 3, 4, -10]
Output 1:
    10
Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output 2:
    6
*/
