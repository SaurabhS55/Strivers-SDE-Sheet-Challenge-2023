// Largest subarray with 0 sum
//code:

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
    map<int,int> m;
    int ans=0,s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        if(s==0){
            ans=max(ans,i+1);
        }
        if(m.find(s)!=m.end()){
            ans=max(ans,i-m[s]);
        }
        if(m.find(s)==m.end()){
            m[s]=i;
        }
    }
    return ans;
    }
};