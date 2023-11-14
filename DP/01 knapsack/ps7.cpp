//count of subsets sum with a given sum
//i/p: arr=[2,3,5,6,8,10], n=6, sum=10 o/p: 

#include<bits/stdc++.h>
using namespace std;
//tabulation- bottom up dp tc- ,sc- 
int subSum(vector<int> arr,int n,int s){
    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
    //base case
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<s+1;j++){    I have commented this Base case because
    //         if(i==0)dp[i][j]=0;    it fails when 0's are present in array so we can't
    //         if(j==0)dp[i][j]=1;    assign dp[i][j]=1 when s=0;
    //     }
    // }
    //instead we only can define a sure BC:
    dp[0][0]=1;
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