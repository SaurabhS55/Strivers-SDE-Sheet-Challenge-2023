//Find Duplicate in Array (medium) leetcode-287
// url: https://leetcode.com/problems/find-the-duplicate-number

//Approach 1- using map
//Time Complexity : O(n)
//Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	map<int,int> m;
	int duplicate;
	for(int i:arr){
		m[i]++;
	}
	for(auto i:m){
		if(i.second>1){
			duplicate=i.first;
			break;
		}
	}
	return duplicate;
}

// Approach: 2 using binary search
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int min=0,max=n-1;
	while(min<=max){
		int mid=min+(max-min)/2;
		int c=0;
		for(int i:arr){
			if(i<=mid){
				c++;
			}
		}
		if(c<=mid){
			min=mid+1;
		}
		else{
			max=mid-1;
		}
	}
	return min;

// Approach: 3 using linked cycle method
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int s=nums[0],f=nums[0];
    do{
        s=nums[s];
        f=nums[nums[f]];
    }while(s!=f);
    f=nums[0];
    while(s!=f){
        s=nums[s];
        f=nums[f];
    }
    return s;

        
    }
};