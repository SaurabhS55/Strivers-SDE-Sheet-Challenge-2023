//find kth smallest element from array

#include<bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> nums,int n,int k){
    priority_queue<int> pq;
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
    cout<<"\n kth smallest element: "<<kthsmallest(nums,n,k);
    return 0;
}