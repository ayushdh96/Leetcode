class Solution {
  private:
  void dfs(int node,vector<int>& vis, vector<vector<int>>& adj,vector<int>& ans){
      vis[node]=1;
      ans.push_back(node);
      for(auto it: adj[node]){
          if(vis[it]==0){
              dfs(it, vis, adj, ans);
          }
      }
  }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(),0);
        vector<int> ans;
        dfs(0,vis,adj,ans);
        return ans;
        
    }
};