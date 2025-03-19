class Solution {
private:
int counter=0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        // Instead of int vis[m][n];
vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        vector<pair<int, int>> movement={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int nrow=q.front().first.first;
            int ncol=q.front().first.second;
            int t=q.front().second;
            counter=max(t,counter);
            q.pop();
            for(auto it:movement){
                int r=nrow+it.first;
                int l=ncol+it.second;
                if(r<m&&r>=0&&l>=0 && l<n && grid[r][l]==1 && vis[r][l]==0){
                    vis[r][l]=1;
                    q.push({{r,l},t+1});
                    
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return counter;
    }
};