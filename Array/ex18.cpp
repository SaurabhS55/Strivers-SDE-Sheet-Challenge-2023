// Longest substring without repeating characters
// leetcode 3
// url: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int l=0,ans=0;
        for(int i=0;i<s.length();i++){
            while(st.find(s[i])!=st.end()){
                st.erase(st.find(s[l]));
                l++;
            }
            st.insert(s[i]);
            ans=max(ans,i-l+1);
        }
        return ans;
        
    }
};