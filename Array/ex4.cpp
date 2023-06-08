//set matrix zeros leetcode-73
// url : https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<int> row(r,0);
        vector<int> column(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(row[i]||column[j]){
                   matrix[i][j]=0;
               }
           }
       }
        
    }
};