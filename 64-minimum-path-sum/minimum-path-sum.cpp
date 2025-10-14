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
        return movement(m-1,n-1,dp,grid);
    }
};