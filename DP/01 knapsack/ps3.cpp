// frog jump

// 1. using top down dp

// #include<bits/stdc++.h>
// using namespace std;
// int solve(int n,vector<int>& h,vector<int>& t){
//     if(n==0)return 0;
//     if(t[n]!=-1)return t[n];
//     return t[n]=min(abs(h[n-1]-h[n])+solve(n-1,h,t),
//     (n>1)?abs(h[n-2]-h[n])+solve(n-2,h,t):INT_MAX);
// }
// int frog(int n,vector<int>& h){
//     vector<int> t(n+1,-1);
//     return solve(n-1,h,t);
// }
// int main()
// {
//     int n;
//     cout<<"\n Enter no. of stairs: ";
//     cin>>n;
//     cout<<"\n Enter array of stairs: ";
//     vector<int> h(n);
//     for(int i=0;i<n;i++){
//         cin>>h[i];
//     }
//     cout<<"min. Energy of frog: " << frog(n,h);
//     return 0;
// }

//2. bottom up dp
#include<bits/stdc++.h>
using namespace std;
// int solve(int n,vector<int>& h,vector<int>& t){
//     if(n==0)return 0;
//     if(t[n]!=-1)return t[n];
//     return t[n]=min(abs(h[n-1]-h[n])+solve(n-1,h,t),
//     (n>1)?abs(h[n-2]-h[n])+solve(n-2,h,t):INT_MAX);
// }
int frog(int n,vector<int>& h){
    if(n==0)return 0;
    vector<int> t(n+1,-1);
    t[0]=0;
    for(int i=n;i>=1;i--){
        t[i]=min(abs(h[i-1]-h[i])+t[i-1],(i>1)?abs(h[i-2]-h[i])+t[i-2]:INT_MAX);
    }
    return t[n];
}
int main()
{
    int n;
    cout<<"\n Enter no. of stairs: ";
    cin>>n;
    cout<<"\n Enter array of stairs: ";
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<"min. Energy of frog: " << frog(n,h);
    return 0;
}