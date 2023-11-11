//K Closest Elements

#include<bits/stdc++.h>
using namespace std;

vector<int> kClosest(vector<int> nums,int n,int k,int x){
    vector<int> v;
    priority_queue<pair<int,int>> pq;
    for(int i:nums){
        pq.push({abs(i-x),i});
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
    cout<<"\n Enter size of array and k and x: "<<endl;
    cin>>n>>k>>x;
    vector<int> nums(n);
    cout<<"\n Enter array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> v1=kClosest(nums,n,k,x);
    cout<<"K sorted array: "<<endl;
    for(int i:v1){
        cout<<i<<" ";
    }
    return 0;
}