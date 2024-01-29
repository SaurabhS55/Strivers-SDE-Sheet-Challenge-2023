// Rod Cutting problem

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

#include<bits/stdc++.h>
using namespace std;
//Tabulation Approach
int cutRod(vector<int> price, int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        vector<int> len;
        for(int i=1;i<=n;i++)len.push_back(i);
        for(int i=0;i<n;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(len[i-1]<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];        
    }
int main(){
    int n;
    cout<<"\n Enter size of array: "<<endl;
    cin>>n;
    vector<int> price(n);
    cout<<"\n Enter price array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<"\n Max value after rod cutting: "<<cutRod(price,n);
    return 0;
}