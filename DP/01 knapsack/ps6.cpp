// equal sum partition 
//i/p: arr,size
//o/p: true
//ex: i/p- arr=[1,5,11,5] size=4, o/p- true
// [1,5,5] and [11] partitions are possible so it is true

#include<bits/stdc++.h>
using namespace std;
//tabulation approach (bottom-up dp) tc- ,sc- 
bool subsetSum(vector<int>& arr,int n,int s){
    vector<vector<bool>> dp(n+1,vector<bool>(s+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}
bool equalPartition(vector<int>& arr,int n){
    int s=0;
    for(int i=0;i<n;i++)s+=arr[i];
    if(s%2!=0)return false;
    else{
        return subsetSum(arr,n,s/2);
    }
}

//driver code
int main(){
    int n;
    cout<<"\n Enter size of array: "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"\n Enter array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<equalPartition(arr,n);
    return 0;
}