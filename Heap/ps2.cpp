//find kth largest element from array

#include<bits/stdc++.h>
using namespace std;

int kthlargest(vector<int> nums,int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i:nums){
        pq.push(i);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
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
    cout<<"\n kth smallest element: "<<kthlargest(nums,n,k);
    return 0;
}