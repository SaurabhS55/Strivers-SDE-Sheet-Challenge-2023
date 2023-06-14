//stock and buy sell
// leetcode : 121
// url : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int p=0;
        for(int i:prices){
            if(i<min){
                min=i;
            }
            else if((i-min)>p){
                p=i-min;
            }
        }
        return p;
    }
};