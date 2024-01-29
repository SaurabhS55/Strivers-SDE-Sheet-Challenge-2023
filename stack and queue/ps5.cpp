//NSR
#include<bits/stdc++.h>
using namespace std;
vector<int> NSR(vector<int>& nums,int n){
    stack<int> st;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()>=nums[i]){
            st.pop();
        }
        if(st.empty())ans.push_back(-1);
        else{
            ans.push_back(st.top());
        }
        st.push(nums[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=NSR(nums,n);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}