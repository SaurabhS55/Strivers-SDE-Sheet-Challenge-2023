// climbing stairs (recursion) tc-o(2^n) sc-o(n)
// #include<iostream>
// using namespace std;
// int climb(int n){
//     if(n==0||n==1||n==2)return n;
//     return climb(n-1)+climb(n-2);
// }
// int main()
// {   
//     cout<<"Enter stairs: ";
//     int n;
//     cin>>n;
//     cout<<"No. of ways to climb "<<n<<" stairs are: "<<climb(n); 
//     return 0;
// }

// top-down dp tc-o(n) sc-o(2n)
// #include<bits/stdc++.h>
// using namespace std;
// int climb(int n,vector<int>& t){
//     if(n==0||n==1||n==2)return n;
//     if(t[n]!=-1)return t[n];
//     return t[n]=climb(n-1,t)+climb(n-2,t);
// }
// int main()
// {   
//     cout<<"Enter stairs: ";
//     int n;
//     cin>>n;
//     vector<int> t(n+1,-1);
//     cout<<"No. of ways to climb "<<n<<" stairs are: "<<climb(n,t); 
//     return 0;
// }

//bottom up tc-o(n), sc-o(n)
// #include<bits/stdc++.h>
// using namespace std;
// int climb(int n){
//     if(n<=2)return n;
//     vector<int> t(n+1);
//     t[0]=0;t[1]=1;t[2]=2;
//     for(int i=3;i<=n;i++){
//         t[i]=t[i-1]+t[i-2];
//     }
//     return t[n];
// }
// int main()
// {   
//     cout<<"Enter stairs: ";
//     int n;
//     cin>>n;
//     cout<<"No. of ways to climb "<<n<<" stairs are: "<<climb(n); 
//     return 0;
// }

//space optimization tc-o(n) sc-o(1)
#include<iostream>
using namespace std;
int climb(int n){
    if(n==0||n==1||n==2)return n;
    int p1=1,p2=2;
    for(int i=3;i<=n;i++){
        int temp=p2+p1;
        p1=p2;
        p2=temp;
    }
    return p2;
}
int main()
{   
    cout<<"Enter stairs: ";
    int n;
    cin>>n;
    cout<<"No. of ways to climb "<<n<<" stairs are: "<<climb(n); 
    return 0;
}