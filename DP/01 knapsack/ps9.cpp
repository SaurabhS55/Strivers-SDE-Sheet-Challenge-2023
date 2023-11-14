//count the number of subsets with given difference d
//i/p- arr=[1,1,2,3], d=1
//o/p- 3 ([1,1,2]-[3]),([1,3]-[1,2]),([1,2]-[1,3])

#include<bits/stdc++.h>
using namespace std;

//tabulation approach
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
        for(int j=0;j<s+1;j++){
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
int diffCount(vector<int>& nums,int n,int d){
    int s=0;
    for(int i:nums)s+=i;
    int s1=(s+d)/2;
    return subSum(nums,n,s1);
}
int main(){
    int n,d;
    cout<<"\n Enter size of array and difference : "<<endl;
    cin>>n>>d;
    cout<<"\n Enter array: "<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"\n Count of difference = "<<diffCount(v,n,d);
    return 0;
}