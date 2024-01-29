// 	Inversion of Array (Pre-req: Merge Sort)
// codestudio
// url : https://www.codingninjas.com/studio/problems/count-inversions_615?leftPanelTab=0

#include <bits/stdc++.h>
int merge(long long int* arr,int s,int m,int e){
    vector<int> v;
    int l=s,r=m+1;
    int c=0;
    while(l<=m&&r<=e){
        if(arr[l]<=arr[r]){
            v.push_back(arr[l]);
            l++;
        }
        else{
            v.push_back(arr[r]);
            c+=(m-l+1);
            r++;
        }
    }
    while(l<=m){
        v.push_back(arr[l]);
        l++;
    }
    while(r<=e){
        v.push_back(arr[r]);
        r++;
    }
    for(int i=s;i<=e;i++){
       arr[i] = v[i-s];
    }
    return c;

}
int sort(long long int* arr,int s,int e){
    int c=0;
    if(s<e){
        int m=s+(e-s)/2;
        c+=sort(arr,s,m);
        c+=sort(arr,m+1,e);
        c+=merge(arr,s,m,e);
    }
    return c;
}
long long getInversions(long long *arr, int n){
    return sort(arr,0,n-1);
    
}