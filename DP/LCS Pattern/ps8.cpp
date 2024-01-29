// Longest Repeating Subsequence
// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y 
// 0 1 2 3 4 5

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.


#include<bits/stdc++.h>
using namespace std;

		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s=str;
		    int n=str.length();
		    vector<int> dp(n+1,0);
		    for(int i=1;i<n+1;i++){
		        vector<int> temp(n+1,0);
		        for(int j=1;j<n+1;j++){
		            if(str[i-1]==s[j-1]&&i!=j){
		                temp[j]=1+dp[j-1];
		            }
		            else{
		                temp[j]=max(dp[j],temp[j-1]);
		            }
		        }
		        dp=temp;
		    }
		    return dp[n];
		}
int main(){
    string s1;
    cout<<"\n Enter string";
    cin>>s1;
    cout<<"LPS= "<<LongestRepeatingSubsequence(s1);
    return 0;
}