// User function Template for C++
class Solution {
  public:
  void dfs(int Node, vector<vector<pair<int,int>>>& adj,stack<int>& st,vector<int>& vis){
      vis[Node]=1;
      for(int i=0;i<adj[Node].size();i++){
          if(vis[adj[Node][i].first]==0) dfs(adj[Node][i].first,adj,st,vis);
      }
      st.push(Node);
  }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> vis(V,0);
        vector<int> ans(V,INT_MAX);
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                dfs(i,adj,st,vis);
            }
        }
        ans[0]=0;
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            if(ans[curr]==INT_MAX){
                ans[curr]=-1;
                continue;
            }
            for(int i=0;i<adj[curr].size();i++){
                if(ans[adj[curr][i].first]>ans[curr]+ adj[curr][i].second){
                    ans[adj[curr][i].first]=ans[curr]+ adj[curr][i].second;
                }
            }
        }
        return ans;
    }
};
