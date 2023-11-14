//minimum subset sum difference
//input: arr=[2,6,11,5] n=4
//output: 2 ([2,5,6]-[11]=2)

#include<bits/stdc++.h>
using namespace std;

//Tabulation method TC- ,SC-
int subSum(vector<int>& arr,int n,int s){
    vector<vector<bool>> dp(n+1,vector<bool>(s+1));
    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
        }
    }
    //choice diagram logic implementation
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
    int ans=INT_MAX;
    for(int i=0;i<=s/2;i++){
        if(dp[n][i]){
            ans=min(ans,abs(s-2*i));
        }
    }
    return ans;
}
int minSubDiff(vector<int>& nums,int n){
    int s=0;
    for(int i:nums)s+=i;
    return subSum(nums,n,s);
}
int main(){
    int n;
    cout<<"\n Enter size of array : "<<endl;
    cin>>n;
    cout<<"\n Enter array: "<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"\n minimum difference of subset sum= "<<minSubDiff(v,n);
    return 0;
}