//target sum
//i/p: arr=[1,2,3,1], n=4, target=3
//o/p: 2 ([-1,+2,+3,-1],[+1,-2,+3,+1])

#include<bits/stdc++.h>
using namespace std;

//tabulation approach

int subSum(vector<int> arr,int n,int s){
    vector<vector<int>> dp(n+1,vector<int>(s+1));
    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    //choice diagram logic implementation
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]+0+dp[i-1][j];
            }
            else{
                dp[i][j]=0+dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}
int targetSum(vector<int>& nums,int n,int target){
    int s=0;
    for(int i:nums)s+=i;
    int s1=(s+target)/2;
    return subSum(nums,n,s1);
}
int main(){
    int n,target;
    cout<<"\n Enter size of array and target : "<<endl;
    cin>>n>>target;
    cout<<"\n Enter array: "<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"\n Count of target sum = "<<targetSum(v,n,target);
    return 0;
}