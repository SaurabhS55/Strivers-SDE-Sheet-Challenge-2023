//sort a k sorted array

#include<bits/stdc++.h>
using namespace std;

vector<int> kSortedArray(vector<int> nums,int n,int k){
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i:nums){
        pq.push(i);
        if(pq.size()>k){
            v.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
int main(){
    int n,k;
    cout<<"\n Enter size of array and k: "<<endl;
    cin>>n>>k;
    vector<int> nums(n);
    cout<<"\n Enter array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> v1=kSortedArray(nums,n,k);
    cout<<"K sorted array: "<<endl;
    for(int i:v1){
        cout<<i<<" ";
    }
    return 0;
}