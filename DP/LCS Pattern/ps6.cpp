//longest palindromic subsequence
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// space optimization
#include<bits/stdc++.h>
using namespace std;
int lps(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.length();
        vector<int> dp(n+1,0);
        //dp table
        for(int i=1;i<n+1;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<n+1;j++){
                if(s[i-1]==s1[j-1]){
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
    cout<<"LPS= "<<lps(s1);
    return 0;
}