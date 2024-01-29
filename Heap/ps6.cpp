//k closest point to origin
#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> v;
        for(int i=0;i<points.size();i++){
            pq.push({(pow(points[i][0],2)+pow(points[i][1],2)),{points[i][0],points[i][1]}});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            v.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return v;
    }
int main(){
    int n,k;
    cout<<"\n Enter size of array and k : "<<endl;
    cin>>n>>k;
    vector<vector<int>> nums(n,vector<int>(2));
    cout<<"\n Enter array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    vector<vector<int>> v1=kClosest(nums,k);
    cout<<"K sorted array: "<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i][0]<<" "<<v1[i][1]<<endl;
    }
    return 0;
}