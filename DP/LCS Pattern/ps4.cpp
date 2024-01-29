//printing longest common supersequence
// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

#include<bits/stdc++.h>
using namespace std;

//bottom up approach
string printLongSupSeq(string s1,string s2){
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    //base case
    for(int i=0;i<m+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    //dp table
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int i=n,j=m;
    string str;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            str+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            str+=s1[i-1];
            i--;
        }
        else{
            str+=s2[j-1];
            j--;
        }
    }
    while(i>0){
        str+=s1[i-1];
        i--;
    }
    while(j>0){
        str+=s2[j-1];
        j--;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main(){
    string s1,s2;
    cout<<"\n Enter string 1 and string 2: ";
    cin>>s1>>s2;
    cout<<"LCS= "<<printLongSupSeq(s1,s2);
    return 0;
}