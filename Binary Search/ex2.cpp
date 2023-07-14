// Search in Rotated Sorted Array
// leetcode - 33
// url: https://leetcode.com/problems/search-in-rotated-sorted-array/

int binarySearch(int *arr,int start,int end,int key){
    int min=start,max=end;
    while(min<=max){
        int mid=min+(max-min)/2;
        if(key==arr[mid])return mid;
        else if(key>arr[mid])min=mid+1;
        else max=mid-1;
    }
    return -1;
}
int pivote(int *arr,int n){
    int min=0,max=n-1;
    while(min<max){
        int mid=min+(max-min)/2;
        if(arr[mid]>=arr[0]){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }
    return min;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int p=pivote(arr,n);
    // cout<<" pivote "<<;
    if(arr[p]<=key && key<=arr[n-1]){
        return binarySearch(arr,p,n-1,key);
    }
    else{
        return binarySearch(arr,0,p-1,key);
    }
}