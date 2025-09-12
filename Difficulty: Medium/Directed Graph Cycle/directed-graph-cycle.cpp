class Solution {
  private:
  void dfs(int Node,vector<int>& vis,vector<int>& path, vector<vector<int>>& adj, bool& cyclic){
      if(cyclic) return;
      vis[Node]=1;
      path[Node]=1;
      for(int i=0;i<adj[Node].size();i++){
          if(vis[adj[Node][i]]==1 && path[adj[Node][i]]==1){
              cyclic=true;
              return;
          }
          else if(vis[adj[Node][i]]==0){
              dfs(adj[Node][i],vis,path,adj,cyclic);
          }
      }
      path[Node]=0;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<vector<int>> adj(V);
        bool cyclic=false;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,path,adj,cyclic);
            }
            if(cyclic) return true;
        }
        return cyclic;
    }
};