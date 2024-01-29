//unbounded knapsack
// Input: 
// N = 4
// W = 8
// val[] = {6, 1, 7, 7}
// wt[] = {1, 3, 4, 5}
// Output: 
// 48
// Explanation: 
// The optimal choice is to pick the 1st element 8 times.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

    //1. Memoization
    // int dp[1001][1001];
    // int solve(int n,int w,int val[],int wt[]){
    //     if(w==0||n==0)return 0;
    //     if(dp[n][w]!=-1)return dp[n][w];
    //     if(wt[n-1]<=w){
    //         return dp[n][w]=max(val[n-1]+solve(n,w-wt[n-1],val,wt),solve(n-1,w,val,wt));
    //     }
    //     else{
    //         return dp[n][w]=solve(n-1,w,val,wt);
    //     }
    // }
    // int knapSack(int N, int W, int val[], int wt[])
    // {
        // memset(dp,-1,sizeof(dp));
    //     return solve(N,W,val,wt);
    // }

    // Tabulation
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1));
        //base case
        for(int i=0;i<N+1;i++)dp[i][0]=0;
        for(int i=0;i<W+1;i++)dp[0][i]=0;
        //choice diagram designing
        for(int i=1;i<N+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }

int main(){
   
    int N, W;
    cin>>N>>W;
    int val[N], wt[N];
    for(int i = 0;i < N;i++)
        cin>>val[i];
    for(int i = 0;i < N;i++)
        cin>>wt[i];
    cout<<"Max profit: "<<knapSack(N, W, val, wt)<<endl;
    return 0;
}
