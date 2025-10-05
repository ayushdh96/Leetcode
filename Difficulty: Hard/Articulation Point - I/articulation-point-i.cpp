// User function Template for C++

class Solution {
  public:
  void dfs(int Node, vector<int> adj[], vector<int>& vis, int parent, int& timer, vector<int>& tin, vector<int>& low, vector<int>& mark){
      vis[Node]=1;
      low[Node]=timer;
      tin[Node]=timer;
      timer++;
      int child=0;
      for(int i=0;i<adj[Node].size();i++){
          int currNode=adj[Node][i];
          if(currNode==parent) continue;
          if(vis[currNode]==0){
              dfs(currNode,adj,vis,Node,timer,tin,low,mark);
              low[Node]=min(low[Node],low[currNode]);
              if(low[currNode]>=tin[Node] && parent!=-1){
                  mark[Node]=1;
              }
              child++;
          }
          else{
              low[Node]=min(tin[currNode],low[Node]);
          }
      }
      if(child>1 && parent==-1) mark[Node]=1;
  }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> mark(V,0);
        int timer=1;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,-1,timer,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int it=0;it<mark.size();it++){
            if(mark[it]==1) ans.push_back(it);
        }
        if(ans.size()>0) return ans;
        else return {-1};
        
    }
};