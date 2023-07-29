// Subset Sums

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void solve(vector<int> arr,int index,int N,vector<int>& ans,vector<int> temp){
        if(index>=N){
            if(temp.size()==0)ans.push_back(0);
            else{
                int t=accumulate(temp.begin(),temp.end(),0);
                ans.push_back(t);
            }
            return;
        }
        solve(arr,index+1,N,ans,temp);
        temp.push_back(arr[index]);
        solve(arr,index+1,N,ans,temp);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> temp;
        if(N==0)return ans;
        solve(arr,0,N,ans,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends