class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int top=0,bottom=mat.size()-1;
        while(top<bottom){
            int oldTop=top;
            if(mat[top][bottom]==1)
                top++;
            else
                bottom--;
        }
        if(top>bottom) return -1;
        for(int i=0;i<mat[0].size();i++){
            if(mat[top][i]!=0 && i!=top) return -1;
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][top]!=1 && i!=top) return -1;
        }
        return top;
    }
};