class Solution {
private:
    int movement(int row, int col, vector<vector<int>>& triangle, int m, vector<vector<int>>& dp){
        if(row==m-1) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        long long down=INT_MAX, right=INT_MAX;
        if(row+1<m)  down=long(triangle[row][col]) + movement(row+1,col,triangle,m, dp);
        if(row+1<m && col+1<triangle[row+1].size()) right=long(triangle[row][col]) + movement(row+1,col+1,triangle,m, dp);
        return dp[row][col]=min(down,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(triangle[m-1].size(),-1));
        for(int i=0;i<triangle[m-1].size();i++){
            dp[m-1][i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i; j>=0;j--){
                 int down=triangle[i][j] + dp[i+1][j];
                 int right=triangle[i][j] + dp[i+1][j+1];
                 dp[i][j]=min(down,right);
            }
        }
        return dp[0][0];
    }
};