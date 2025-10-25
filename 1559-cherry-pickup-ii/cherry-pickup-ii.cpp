class Solution {
private:
    int recur(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()){
            return -1e9;
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maximus=INT_MIN;
        for(int first=-1;first<=1;first++){
            for(int second=-1;second<=1;second++){
                int value;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1] + grid[i][j2];
                value=value+ recur(i+1,j1+first,j2+second,grid,dp);
                maximus=max(maximus,value);
            }
        }
        return dp[i][j1][j2]=maximus;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        return recur(0,0,col-1,grid,dp);
    }
};