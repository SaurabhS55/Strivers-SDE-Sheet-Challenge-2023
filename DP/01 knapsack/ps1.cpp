//fibonacci series tc-o(2n), sc-o(2n) top-down dp
// #include<bits/stdc++.h>
// using namespace std;
// int solve(int n,vector<int>& t){
//     if(n==0)return 0;
//     else if(n==1)return 1;
//     if(t[n]!=-1)return t[n];
//     return t[n]=solve(n-2,t)+solve(n-1,t);
// }
// vector<int> printFibonacci(int n,vector<int>& t){
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         v.push_back(solve(i,t));
//     }
//     return v;
// }
// int main(){
//     int n;
//     cout<<"\n Enter the number: ";
//     cin>>n;
//     cout<<"\n The fibonacci series is: ";
//     vector<int> t(n+1,-1);
//     vector<int> temp=printFibonacci(n,t);
//     for(auto i:temp){
//         cout<<i<<" ";
//     }
//     return 0;
// }

//bottom-up dp tc-o(n) sc-o(n)
// #include<bits/stdc++.h>
// using namespace std;
// int printFibonacci(int n){
//     if(n==0||n==1)return n;
//     vector<int> t(n+1);
//     t[0]=0;
//     t[1]=1;
//     for(int i=2;i<=n;i++){
//         t[i]=t[i-2]+t[i-1];
//     }
//     return t[n];
// }
// int main(){
//     int n;
//     cout<<"\n Enter the number: ";
//     cin>>n;
//     cout<<"\n The fibonacci series is: ";
//     for(int i=0;i<n;i++){
//         cout<<printFibonacci(i)<<" ";
//     }
//     return 0;
// }

//space optimization tc-o(n) sc-o(1)

#include<bits/stdc++.h>
using namespace std;
int printFibonacci(int n){
    if(n==0||n==1)return n;
    int p1=0;
    int p2=1;
    for(int i=2;i<=n;i++){
        int temp=p1+p2;
        p1=p2;
        p2=temp;
    }
    return p2;
}
int main(){
    int n;
    cout<<"\n Enter the number: ";
    cin>>n;
    cout<<"\n The fibonacci series is: ";
    for(int i=0;i<n;i++){
        cout<<printFibonacci(i)<<" ";
    }
    return 0;
}