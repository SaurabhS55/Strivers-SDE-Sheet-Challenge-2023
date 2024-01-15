//  Number Of Nodes
#include<bits/stdc++.h>
using namespace std;
int numberOfNodes(int N){
    // Write your code here.
    return pow(2,N-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<numberOfNodes(n);
    return 0;
}