//0-1 knapsack problem
//input: weight array, value array, capacity of bag and size of weight and value array
//output: max profit in terms of value by sniffing object of weight w in weight array.

#include<bits/stdc++.h>
using namespace std;

//1. memoization- top down dp  TC: O(n x w) , SC: O(n x w)+ aux. recursive
// int solve(vector<int>& weight,vector<int> value,int w,int n,vector<vector<int>>& dp){
//     if(w==0||n==0)return 0;
//     if(dp[n][w]!=-1)return dp[n][w];
//     if(weight[n-1]<=w){
//         return dp[n][w]=max(value[n-1]+solve(weight,value,w-value[n-1],n-1,dp),solve(weight,value,w,n-1,dp));
//     }
//     else{
//         return dp[n][w]=solve(weight,value,w,n-1,dp);
//     }
// }
// int knapsack(vector<int>& weight,vector<int> value,int w){
//     int n=weight.size();
//     vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
//     return solve(weight,value,w,n,dp);
// }

//2. Tabulation- bottom up dp  tc- o(n x w) sc-o(n x w)
int knapsack(vector<int>& weight,vector<int>& value,int w){
    int n=weight.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    //choice diagram logic implementation
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weight[i-1]<=w){
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main(){
    cout<<"\n Enter bag capcity: "<<endl;
    int w;
    cin>>w;
    int n;
    cout<<"\n Enter weight and value array size: "<<endl;
    cin>>n;
    vector<int> weight(n),value(n);
    cout<<"\n Enter weight of "<<n<<" objects: "<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"\n Enter value of "<<n<<" objects: "<<endl;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<"\n Max profit we can achive: "<<knapsack(weight,value,w);
    return 0;
}