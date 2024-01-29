//coins change 2
//Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Similar to count subset sum pattern

#include<bits/stdc++.h>
using namespace std;
//Tabulation
int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+0+dp[i-1][j];
                }
                else{
                    dp[i][j]=0+dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
//driver code
int main(){
    int n,amt;
    cout<<"\n Enter size of array and total amount "<<endl;
    cin>>n;
    cin>>amt;
    cout<<"\n Enter array of values: "<<endl;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<change(amt,arr);
    return 0;
}