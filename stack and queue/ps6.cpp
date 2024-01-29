#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(int n,vector<int>& nums){
    vector<int> ans;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int c=1;
        while(!st.empty()&&st.top().first<nums[i]){
            c+=st.top().second;
            st.pop();
        }
        st.push({nums[i],c});
        ans.push_back(c);
    }
    return ans;
}
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int> ans=stockSpan(n,v);
  for(int i:ans){
    cout<<i<<" ";
  }
  return 0;
}