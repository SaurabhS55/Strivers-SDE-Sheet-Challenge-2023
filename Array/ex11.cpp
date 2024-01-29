//Majority element
// leetcode: 169
// url: https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int c=1,max;
       max=nums[0];
       for(int i=1;i<nums.size();i++){
           if(max==nums[i]){
               c++;
           }
           else if(c==0){
               max=nums[i];
               c++;
           }
           else{
               c--;
           }
       }
       int c1=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==max)
                c1++;
       }
       return (c1>nums.size()/2)?max:-1;
    }
};