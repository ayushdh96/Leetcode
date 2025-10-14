class Solution {
private:
    int movement(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(row<0 || col<0) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==0 && col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up=movement(row-1,col,dp,obstacleGrid);
        int left=movement(row,col-1,dp,obstacleGrid);
        return dp[row][col]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return movement(m-1,n-1,dp,obstacleGrid);
    }
};