class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(),0);
        vector<int> ans;
        vector<vector<int>> adj(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0) {q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0) q.push(adj[curr][i]);
            }
        }
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
    }
};