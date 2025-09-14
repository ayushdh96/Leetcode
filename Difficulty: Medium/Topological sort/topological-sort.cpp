class Solution {
  void dfs(int Node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
      vis[Node]=1;
      for(int i=0;i<adj[Node].size();i++){
          if(vis[adj[Node][i]]==0) dfs(adj[Node][i], adj, vis, st);
      }
      st.push(Node);
  }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};