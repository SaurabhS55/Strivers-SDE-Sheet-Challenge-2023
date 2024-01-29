// Search in 2D matrix (medium) leetcode-74
// url: https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int min=0,max=(row*col)-1;
        while(min<=max){
            int mid=min+(max-min)/2;
            int ele=matrix[mid/col][mid%col];
            if(ele==target){
                return true;
            }
            else if(ele<target){
                min=mid+1;
            }
            else{
                max=mid-1;
            }
        }
        return false;
    }
};