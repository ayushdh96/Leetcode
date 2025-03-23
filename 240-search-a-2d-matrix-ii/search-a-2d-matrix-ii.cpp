class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLeft=0,colTop=0;
        int rowRight=matrix.size();
        int flag=0;
        for(int i=0;i<rowRight;i++){
            colTop=0;
            int colBottom=matrix[i].size()-1;
            while(colTop<=colBottom){
                int mid=(colTop+colBottom)/2;
                if(matrix[i][mid]==target){
                    flag=1;
                    break;
                }
                else if(matrix[i][mid]>target){
                    colBottom=mid-1;
                }
                else{
                    colTop=mid+1;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            return true;}
        else{
            return false;
        }
        return false;
    }
};