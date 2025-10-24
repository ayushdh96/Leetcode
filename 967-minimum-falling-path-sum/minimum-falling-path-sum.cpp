class Solution {
private:
    int recur(int row, int col,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col<0 || col >=matrix[0].size()) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==0) return matrix[row][col];
        int left= matrix[row][col] + recur(row-1,col-1,matrix,dp);
        int up=matrix[row][col] + recur(row-1,col,matrix,dp);
        int right=matrix[row][col] + recur(row-1,col+1,matrix,dp);
        return dp[row][col]=min(left,min(up,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int column=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(rows,vector<int>(column,-1));
        for(int i=0;i<rows;i++){
            //int sum=recur(rows-1,i,matrix,dp);
            //ans=min(sum,ans);
            for(int j=0;j<column;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                int left,right,up;
                if(i>0 && j>0) left= matrix[i][j] + dp[i-1][j-1];
                else left=1e9;
                if(i>0) up=matrix[i][j]  + dp[i-1][j];
                else up=1e9;
                if(i>0 && j<column-1)right=matrix[i][j] + dp[i-1][j+1];
                else right=1e9;
                dp[i][j]=min(left,min(up,right));
                }
            }
        }
        for(int j=0;j<column;j++){
            ans=min(ans,dp[rows-1][j]);
        }
        return ans;
    }
};