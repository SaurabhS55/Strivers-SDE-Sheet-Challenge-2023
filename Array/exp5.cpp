//Sort an array of 0s, 1s and 2s.  leetcode-

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        long k=0;
        for(long i=0;i<n;i++){
            if(a[i]==0){
                swap(a[i],a[k]);
                k++;
            }
        }
        long h=n-1;
        for(long i=n-1;i>=0;i--){
            if(a[i]==2){
                swap(a[i],a[h]);
                h--;
            }
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends