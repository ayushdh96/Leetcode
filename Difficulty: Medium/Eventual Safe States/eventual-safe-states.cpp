// User function Template for C++

class Solution {
  private:
  void dfs(int Node,vector<int>& vis,vector<int>& path, vector<int> adj[], vector<int>& bad){
      vis[Node]=1;
      path[Node]=1;
      for(int i=0;i<adj[Node].size();i++){
          if(vis[adj[Node][i]]==1 && path[adj[Node][i]]==1){
              bad[Node]=1;
              break;
          }
          else if(vis[adj[Node][i]]==0){
              dfs(adj[Node][i],vis,path,adj,bad);
              if(bad[adj[Node][i]]==1) bad[Node]=1;
          }
          else{
              if(bad[adj[Node][i]]==1) bad[Node]=1;
          }
      }
      
      path[Node]=0;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int>ans;
        vector<int> bad(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,path,adj,bad);
            }
        }
        for(int i=0;i<bad.size();i++){
            if(bad[i]==0) {ans.push_back(i);}
        }
        return ans;
        
    }
};
