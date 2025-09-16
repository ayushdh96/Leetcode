class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(),0);
        vector<int> ans;
        vector<vector<int>> adj(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
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
            ans.push_back(curr);
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0) q.push(adj[curr][i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};