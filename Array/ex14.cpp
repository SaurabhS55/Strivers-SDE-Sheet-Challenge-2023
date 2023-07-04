//Maximum Subarray
// leetcode : 53
// url: https://leetcode.com/problems/maximum-subarray/
// kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>m){
                m=s;
            }
            if(s<0){
                s=0;
            }
        }
        return m;
    }
};