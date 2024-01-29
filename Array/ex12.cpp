// majority element ii
// leetcode: 229
// url: https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>(nums.size())/3){
                v.push_back(i.first);
            }
        }
        return v;
    }
};