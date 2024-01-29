//subset sum 
//input:- arr,size, sum value
//output: true/false
//ex- i/p: arr=[2,3,7,8,10] size-5 sum-11 , o/p: true


#include<bits/stdc++.h>
using namespace std;
//tabulation- bottom up dp tc- ,sc- 
bool subSum(vector<int> arr,int n,int s){
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
    return dp[n][s];
}
//driver code
int main(){
    int n,s;
    cout<<"\n Enter size of array and sum value "<<endl;
    cin>>n;
    cin>>s;
    cout<<"\n Enter array of values: "<<endl;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subSum(arr,n,s);
    return 0;
}