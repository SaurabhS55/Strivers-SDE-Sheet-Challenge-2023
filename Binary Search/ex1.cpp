// Single Element in a Sorted Array
// leetcode - 540
// url: https://leetcode.com/problems/single-element-in-a-sorted-array/

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int min=0,max=arr.size()-1;
	while(min<max){
		int mid=min+(max-min)/2;
		if(mid%2==0 && arr[mid]==arr[mid+1] || mid%2!=0 && arr[mid]==arr[mid-1]){
			min=mid+1;
		}
		else{
			max=mid;
		}
	}
	return arr[min];
}