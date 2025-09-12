// User function Template for C++

class Solution {
  private:
  void bfs(pair<int,int> Node,vector<vector<int>>& grid,vector<vector<int>>& vis, vector<pair<int,int>>& temp){
      int m=grid.size();
      int n=grid[0].size();
      int f1=Node.first;
      int f2=Node.second;
      queue<pair<int,int>>q;
      q.push({f1,f2});
      temp.push_back({f1-f1,f2-f2});
      vis[f1][f2]=0;
      while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          if(row+1<m && vis[row+1][col]==0 && grid[row+1][col]==1){
                q.push({row+1,col});
                vis[row+1][col]=1;
                temp.push_back({row+1-f1,col-f2});
            }
            if(row-1>=0 && vis[row-1][col]==0 && grid[row-1][col]==1){
                q.push({row-1,col});
                vis[row-1][col]=1;
                temp.push_back({row-1-f1,col-f2});
            }
            if(col+1<n && vis[row][col+1]==0 && grid[row][col+1]==1){
                q.push({row,col+1});
                vis[row][col+1]=1;
                temp.push_back({row-f1,col+1-f2});
            }
            if(col-1>=0 && vis[row][col-1]==0 && grid[row][col-1]==1){
                q.push({row,col-1});
                vis[row][col-1]=1;
                temp.push_back({row-f1,col-1-f2});
            }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        set<vector<pair<int,int>>> ans;
        vector<pair<int,int>> temp;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]){
                    bfs({i,j},grid,vis,temp);
                
                    ans.insert(temp);
                    temp.clear();
                }
            }
        }
        return ans.size();
    }
};
