// Max Consecutive Ones
//leetcode 485
//url: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,c=0;
        for(int i:nums){
            if(i==1)c++;
            else{
                ans=max(ans,c);
                c=0;
            }
        }
        return max(ans,c);     
    }
};