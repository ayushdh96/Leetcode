
class Solution {
  private:
  void dfs(int node, vector<int>& vis, vector<int>& temp, vector<vector<int>>& adj){
      vis[node]=1;
      temp.push_back(node);
      for(int i=0;i<adj[node].size();i++){
          if(vis[adj[node][i]]==0) dfs(adj[node][i],vis,temp,adj);
      }
  }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V,0);
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,temp, adj);
            }
            if(!temp.empty()){
                ans.push_back(temp);
                temp.clear();
            }
        }
    
        return ans;
    }
};
