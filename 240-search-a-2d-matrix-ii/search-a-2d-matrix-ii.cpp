class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size()-1;
        int row=0;
        int element=0;
        while(col>=0 && row<matrix.size()){
            element=matrix[row][col];
            if(element==target){
                return true;
            }
            else if(target<element){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};