class Solution {
private:
    int movement(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(row<0 || col<0) return INT_MAX;
        if(row==0 && col==0) return grid[0][0];
        if(dp[row][col]!=-1) return dp[row][col];
        long long up=long(grid[row][col])+movement(row-1,col,dp,grid);
        long long left=long(grid[row][col])+movement(row,col-1,dp,grid);
        return dp[row][col]=min(up,left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //return movement(m-1,n-1,dp,grid);
        //writing the code for the tabulation
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=INT_MAX;
                    int right=INT_MAX;
                    if(i>0)  up=grid[i][j]+dp[i-1][j];
                    if(j>0)  right=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,right);
                }
            }
        }
        return dp[m-1][n-1];
    }
};