// Missing and repeating numbers

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long sum1=(n*(n+1))/2;
	long long sq1=(n*(n+1)*(2*n+1))/6;
	long long sum2=0,sq2=0;
	for(int i:arr){
		sum2+=i;
		sq2+=(long long)i*i;
	}
	long long val1=sum2-sum1;
	long long val2=sq2-sq1;
	val2=val2/val1;
	long long x=(val1+val2)/2;
	long long y=(x-val1);
	return{(int)y,(int)x};

}
