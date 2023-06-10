// Longest Consecutive Sequence leetcode-128
// url : https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return 1;
        }
        else{
            sort(nums.begin(),nums.end());
            int s=nums[0],c=1;
            int ans=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i]==nums[i-1]){
                    continue;
                }
                else if(nums[i]==nums[i-1]+1){
                    c++;
                }
                else{
                    ans=max(c,ans);
                    c=1;
                }
            }
            ans=max(c,ans);
            return ans;
        }
    }
};