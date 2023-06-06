//Find Duplicate in Array (Easy)
#include <bits/stdc++.h>

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
