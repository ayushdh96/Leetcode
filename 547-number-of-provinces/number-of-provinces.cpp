class Solution {
private:
  void dfs(int node,vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(vis[i]==0 && adj[node][i]==1){
                dfs(i,vis, adj);
            }
        }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int output=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                output++;
                dfs(i,vis, isConnected);
            }
        }
        return output;

    }
};