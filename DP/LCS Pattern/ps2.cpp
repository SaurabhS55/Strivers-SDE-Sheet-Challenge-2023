//printing Longest common Subsequence (LCS)
//I/P - s1="bacbd" s2="abcbd"
//o/p- acbd

#include<bits/stdc++.h>
using namespace std;

// recursion code
// string solve(string s1,string s2,int n,int m){
//     if(n==0||m==0)return "";
//     if(s1[n-1]==s2[m-1]){
//         return s1[n-1]+solve(s1,s2,n-1,m-1);
//     }
//     else{
//         return (s1.length()>s2.length())?solve(s1,s2,n-1,m):solve(s1,s2,n,m-1);
//     }
// }
// string lcs(string s1,string s2){
//     string str=solve(s1,s2,s1.size(),s2.size());
//     reverse(str.begin(),str.end());
//     return str;
// }


//memoization code
// vector<vector<string>> dp;
// string solve(string s1,string s2,int n,int m){
//     if(n==0||m==0)return "";
//     if(dp[n][m]!="")return dp[n][m];
//     if(s1[n-1]==s2[m-1]){
//         return dp[n][m]=s1[n-1]+solve(s1,s2,n-1,m-1);
//     }
//     else{
//         return dp[n][m]=(s1.length()>s2.length())?solve(s1,s2,n-1,m):solve(s1,s2,n,m-1);
//     }
// }
// string lcs(string s1,string s2){
//     dp.resize(s1.size()+1,vector<string>(s2.size()+1,""));
//     string str=solve(s1,s2,s1.size(),s2.size());
//     reverse(str.begin(),str.end());
//     return str;
// }


//bottom up approach
// string lcs(string s1,string s2){
//     int n=s1.length(),m=s2.length();
//     vector<vector<string>> dp(n+1,vector<string>(m+1));
//     //base case
//     for(int i=0;i<m+1;i++){
//         dp[0][i]="";
//     }
//     for(int i=0;i<n+1;i++){
//         dp[i][0]="";
//     }
//     //dp table
//     for(int i=1;i<n+1;i++){
//         for(int j=1;j<m+1;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=s1[i-1]+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=(dp[i-1][j].length()>dp[i][j-1].length())?dp[i-1][j]:dp[i][j-1];
//             }
//         }
//     }
//     reverse(dp[n][m].begin(),dp[n][m].end());
//     return dp[n][m];
// }


//space optimization
string lcs(string s1,string s2){
    int n=s1.length(),m=s2.length();
    vector<string> dp(m+1,"");
    //dp table
    for(int i=1;i<n+1;i++){
        vector<string> temp(m+1,"");
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                temp[j]=s1[i-1]+dp[j-1];
            }
            else{
                temp[j]=(temp[j-1].length()>dp[j].length())?temp[j-1]:dp[j];
            }
        }
        dp=temp;
    }
    reverse(dp[m].begin(),dp[m].end());
    return dp[m];
}

int main(){
    string s1,s2;
    cout<<"\n Enter string 1 and string 2: ";
    cin>>s1>>s2;
    cout<<"LCS= "<<lcs(s1,s2);
    return 0;
}
