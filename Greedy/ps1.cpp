//N meetings in one room
// Input:
// N = 6
// start[] = {1,3,0,5,8,5}
// end[] =  {2,4,6,7,9,9}
// Output: 
// 4
// Explanation:
// Maximum four meetings can be held with
// given start and end timings.
// The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

#include<bits/stdc++.h>
using namespace std;
int maxMeetings(vector<int> start,vector<int> end,int n){
    int n=start.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({end[i],start[i]});
        }
        int c=1;
        int p=pq.top().first;
        pq.pop();
        while(!pq.empty()){
            int t=pq.top().second;
            if(t>p){
                c++;
                p=pq.top().first;
            }
            pq.pop();
        }
        return c;
}
//driver code
int main(){
    int n;
    cout<<"\n Enter size of array: "<<endl;
    cin>>n;
    vector<int> start(n),end(n);
    cout<<"\n Enter start array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    cout<<"\n Enter end array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    cout<<"Max count of meetings: "<<maxMeetings(start,end,n);
    return 0;
}