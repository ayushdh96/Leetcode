class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,left=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
        vector<int> spiral;
        while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            spiral.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            spiral.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            spiral.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            spiral.push_back(matrix[i][left]);
        }
        left++;
        }
        }
        return spiral;
    }
};