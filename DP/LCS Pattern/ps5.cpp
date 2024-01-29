//Minimum number of insertion and deletion to make the string A to B
//i/p: a=heap b=pea
// o/p: insertion=1(p) deletion=2(h and p) {1,2}
#include<bits/stdc++.h>
using namespace std;
//space optimization
pair<int,int> minInsDel(string s1,string s2){
    int n=s1.length(),m=s2.length();
    vector<int> dp(m+1,0);
    //dp table
    for(int i=1;i<n+1;i++){
        vector<int> temp(m+1,0);
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                temp[j]=1+dp[j-1];
            }
            else{
                temp[j]=max(temp[j-1],dp[j]);
            }
        }
        dp=temp;
    }
    return {m-dp[m],n-dp[m]};
}
int main(){
    string s1,s2;
    cout<<"\n Enter string 1 and string 2: ";
    cin>>s1>>s2;
    pair<int,int> p=minInsDel(s1,s2);
    cout<<"Min ins= "<<p.first<<"\nMin del= "<<p.second;
    return 0;
}