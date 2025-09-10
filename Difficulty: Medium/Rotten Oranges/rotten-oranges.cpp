class Solution {
  private:
  void modifiedBFS(vector<vector<int>>& mat,vector<vector<int>>& vis, int n, int m, int& time){
      queue<pair<pair<int,int>,int>> q;
      for(int i=0;i<mat.size();i++){
          for(int j=0;j<mat[0].size();j++){
              if(mat[i][j]==2){
                  vis[i][j]=1;
                  q.push({{i,j},0});
              }
          }
      }
      while(!q.empty()){
          int n=q.front().first.first;
          int m=q.front().first.second;
          int currTime=q.front().second;
          if(currTime>time) time=currTime;
          q.pop();
          if(n-1>=0 && vis[n-1][m]==0 && mat[n-1][m]==1){
              q.push({{n-1,m},currTime+1});
              mat[n-1][m]=2;
          }
          if(n+1<mat.size() && vis[n+1][m]==0 && mat[n+1][m]==1){
              q.push({{n+1,m},currTime+1});
              mat[n+1][m]=2;
          }
          if(m-1>=0 && vis[n][m-1]==0 && mat[n][m-1]==1){
              q.push({{n,m-1},currTime+1});
              mat[n][m-1]=2;
          }
          if(m+1<mat[n].size() && vis[n][m+1]==0 && mat[n][m+1]==1){
              q.push({{n,m+1},currTime+1});
              mat[n][m+1]=2;
          }
      }
      for(int i=0;i<mat.size();i++){
          for(int j=0;j<mat[i].size();j++){
              if(mat[i][j]==1) {time=-1;return;}
          }
      }
      
  }
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int time=0;
        modifiedBFS(mat,vis, n, m,time);
        return time;
    }
};