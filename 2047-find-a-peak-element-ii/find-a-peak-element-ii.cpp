class Solution {
public:
    int findMaxElement(vector<vector<int>>& mat,int col,int rowsCount){
        int max=-1;
        int rowIndex=-1;
        for(int i=0;i<rowsCount;i++){
            if(mat[i][col]>max){
                max=mat[i][col];
                rowIndex=i;
            }
        }
        return rowIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left=0;
        int right=mat[0].size()-1;
        while(left<=right){
            int leftIndexValue=-1;
            int rightIndexValue=-1;
            int mid=(left+right)/2;
            int maxIndex=findMaxElement(mat,mid, mat.size());
            int currMaxValue=mat[maxIndex][mid];
            if(mid-1>=0){leftIndexValue=mat[maxIndex][mid-1];}
            if(mid+1<mat[0].size()){rightIndexValue=mat[maxIndex][mid+1];}
            if(leftIndexValue<currMaxValue && currMaxValue>rightIndexValue){
                cout<<leftIndexValue<<". "<<currMaxValue<<". "<<rightIndexValue;
                return{maxIndex,mid};
            }
            else{
                if(leftIndexValue>currMaxValue){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }

        }
        return{-1,-1};
    }
};