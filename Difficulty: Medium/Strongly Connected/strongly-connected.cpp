//Position this line where user code will be pasted.
class Solution {
  public:
  void dfs(int Node, vector<vector<int>> &adj, vector<int>& vis, stack<int>& st, bool needStack){
      vis[Node]=1;
      for(int i=0;i<adj[Node].size();i++){
          int currNode=adj[Node][i];
          if(vis[currNode]==0){
              dfs(currNode,adj,vis,st,needStack);
          }
      }
     st.push(Node);
  }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        vector<int> vis(adj.size(),0);
        stack<int> st;
        bool needStack=true;
        for(int i=0;i<adj.size();i++){
                if(vis[i]==0){
                    dfs(i,adj,vis,st,needStack);
                }
            
        }
        vector<vector<int>> revAdj(adj.size());
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                revAdj[adj[i][j]].push_back(i);
            }
        }
        fill(vis.begin(), vis.end(), 0);        // Recommended
        needStack=false;
        int ans=0;
        while(!st.empty()){
            int currNode=st.top();
            st.pop();
            if(vis[currNode]==0){
                dfs(currNode,revAdj,vis,st,needStack);
                ans++;
            }
        }
        return ans;
    }
};