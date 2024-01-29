//  NSL

#include<bits/stdc++.h>
using namespace std;
vector<int> NSL(vector<int>& nums,int n){
    stack<int> st;
    vector<int> v;
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top()>=nums[i]){
            st.pop();
        }
        if(st.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(st.top());
        }
        st.push(nums[i]);
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=NSL(nums,n);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}