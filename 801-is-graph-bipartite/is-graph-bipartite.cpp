class Solution {
private:
    void dfs(int Node, vector<int>& vis, vector<vector<int>>& graph, bool& isBi){
        if(!isBi) return;
        if(vis[Node]==-1) vis[Node]=0;
        for(int i=0; i<graph[Node].size();i++){
            if(vis[graph[Node][i]]==-1){
                if (vis[Node]) vis[graph[Node][i]]=0;
                else vis[graph[Node][i]]=1;
                dfs(graph[Node][i], vis, graph,isBi);
            }
            else{
                if(vis[Node]== vis[graph[Node][i]]) {
                    isBi=false; 
                    return;
                    }
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool isBi=true;
        int size=graph.size();
        vector<int> vis(size,-1);
        for(int i=0;i<size;i++){
            if(vis[i]==-1){
                dfs(i, vis, graph, isBi);
            }
            if(!isBi) return isBi;
        }
    return isBi;
    }
};