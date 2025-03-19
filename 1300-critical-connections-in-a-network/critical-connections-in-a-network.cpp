class Solution {
private:
int timer=1;
private:
void dfs(int parent,int node ,vector<int> &vis, vector<vector<int>> &adj,int low[], int tin[], vector<vector<int>> &bridges){
    vis[node]=1;
    tin[node]=timer;
    low[node]=timer;
    timer++;
    for(auto it: adj[node]){
        if(it==parent)continue;
        if(vis[it]==0){
            dfs(node,it, vis,adj,low,tin,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                bridges.push_back({node,it});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }

}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int low[n];
        int tin[n];
        vector<vector<int>> bridges;
        dfs(-1,0,vis,adj,low,tin,bridges);
        return bridges;
    }
};