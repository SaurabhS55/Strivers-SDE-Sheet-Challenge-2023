//k frequent elements
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
int main(){
    int n,k,x;
    cout<<"\n Enter size of array and k"<<endl;
    cin>>n>>k;
    vector<int> nums(n);
    cout<<"\n Enter array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> v1=topKFrequent(nums,k);
    cout<<"K frequent array: "<<endl;
    for(int i:v1){
        cout<<i<<" ";
    }
    return 0;
}