//Longest common Subsequence (LCS)
//I/P - s1="bacbd" s2="abcbd"
//o/p- 4

#include<bits/stdc++.h>
using namespace std;

// recursion code
// int solve(string s1,string s2,int n,int m){
//     if(n==0||m==0)return 0;
//     if(s1[n-1]==s2[m-1]){
//         return 1+solve(s1,s2,n-1,m-1);
//     }
//     else{
//         return max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
//     }
// }
// int lcs(string s1,string s2){
//     return solve(s1,s2,s1.size(),s2.size());
// }


//memoization code
// vector<vector<int>> dp;
// int solve(string s1,string s2,int n,int m){
//     if(n==0||m==0)return 0;
//     if(dp[n][m]!=-1)return dp[n][m];
//     if(s1[n-1]==s2[m-1]){
//         return dp[n][m]=1+solve(s1,s2,n-1,m-1);
//     }
//     else{
//         return dp[n][m]=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
//     }
// }
// int lcs(string s1,string s2){
//     dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
//     return solve(s1,s2,s1.size(),s2.size());
// }


//bottom up approach
// int lcs(string s1,string s2){
//     int n=s1.length(),m=s2.length();
//     vector<vector<int>> dp(n+1,vector<int>(m+1));
//     //base case
//     for(int i=0;i<m+1;i++){
//         dp[0][i]=0;
//     }
//     for(int i=0;i<n+1;i++){
//         dp[i][0]=0;
//     }
//     //dp table
//     for(int i=1;i<n+1;i++){
//         for(int j=1;j<m+1;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//             }
//         }
//     }
//     return dp[n][m];
// }


//space optimization
int lcs(string s1,string s2){
    int n=s1.length(),m=s2.length();
    vector<int> dp(m+1,0);
    //dp table
    for(int i=1;i<n+1;i++){
        vector<int> temp(m+1,0);
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                temp[j]=1+dp[j-1];
            }
            else{
                temp[j]=max(temp[j-1],dp[j]);
            }
        }
        dp=temp;
    }
    return dp[m];
}

int main(){
    string s1,s2;
    cout<<"\n Enter string 1 and string 2: ";
    cin>>s1>>s2;
    cout<<"LCS= "<<lcs(s1,s2);
    return 0;
}
