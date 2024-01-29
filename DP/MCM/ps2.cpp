//Palindromic partition
#include<bits/stdc++.h>
using namespace std;
//memoization
    int isPalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    int solve(string& s,int i,int j,vector<vector<int>>& dp){
        if(i>=j)return 0;
        if(isPalindrome(s,i,j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                t=min(t,1+solve(s,k+1,j,dp));
            }
        }
        return dp[i][j]=t;
    }
    int minCut(string& s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        return solve(s,0,s.length()-1,dp);
    }

    //Tabulation
    // bool isPalindrome(string& s,int i,int j){
    //     while(i<j){
    //         if(s[i]!=s[j])return false;
    //         i++;j--;
    //     }
    //     return true;
    // }
    // int minCut(string s) {
    //     int n=s.length();
    //     vector<int> dp(n+1,0);
    //     for(int i=n-1;i>=0;i--){
    //         int t=INT_MAX;
    //         for(int j=i;j<n;j++){
    //             if(isPalindrome(s,i,j)){
    //                 t=min(t,1+dp[j+1]);
    //             }
    //         }
    //         dp[i]=t;
    //     }
    //     return dp[0]-1;
    // }
int main(){
    string s;
    cin>>s;
    cout<<minCut(s);
    return 0;
}