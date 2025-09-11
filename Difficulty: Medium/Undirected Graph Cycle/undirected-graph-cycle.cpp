class Solution {
  private:
  void bfs(int node, vector<int>& vis, vector<vector<int>>& adj, bool& situtation){
      vis[node]=1;
      queue<pair<int,int>> q;
      q.push({node,-1});
      while(!q.empty()){
          int currValue=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(int i=0;i<adj[currValue].size();i++){
              if(vis[adj[currValue][i]]==0){
                  q.push({adj[currValue][i],currValue});
                  vis[adj[currValue][i]]=1;
              }
              else{
                  if(parent!=adj[currValue][i]) {situtation=true;
                  break;}
              }
          }
      }
  }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        if(edges.size()<1) return true;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        bool situtation=false;
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                bfs(i, vis, adj, situtation);
            }
            if(situtation == true) return true;
        }
        return situtation;
    }
};