//shortest common supersequence
//Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.

#include<bits/stdc++.h>
using namespace std;

//space optimization
int longSuperSeq(string s1,string s2){
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
    return (s1.length()+s2.length())-dp[m];
}

int main(){
    string s1,s2;
    cout<<"\n Enter string 1 and string 2: ";
    cin>>s1>>s2;
    cout<<"LCS= "<<longSuperSeq(s1,s2);
    return 0;
}