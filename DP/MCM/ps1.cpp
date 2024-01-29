// matrix chain multiplication
#include<bits/stdc++.h>
using namespace std;
//Memoization
// int solve(vector<int>& v,int i,int j,vector<vector<int>>& dp){
//     if(i>=j)return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int ans=INT_MAX;
//     for(int k=i;k<j;k++){
//         ans=min(ans,solve(v,i,k,dp)+solve(v,k+1,j,dp)+(v[i-1]*v[k]*v[j]));
//     }
//     return dp[i][j]=ans;
// }
// int matrixChainMultiplication(vector<int>& v){
//     int n=v.size();
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     return solve(v,1,n-1,dp);
// }

//Tabulation
int matrixChainMultiplication(vector<int>& v){
    int n=v.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int ans=INT_MAX;
            for(int k=i;k<j;k++){
                ans=min(ans,dp[i][k]+dp[k+1][j]+(v[i-1]*v[k]*v[j]));
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<matrixChainMultiplication(v);
    return 0;
}