class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        int indegree[N]={0};
        for(auto it : prerequisites){
            adj[it.second].push_back(it.first);
            indegree[it.first]++;
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int counter=0;
        while(!q.empty()){
            counter++;
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0) q.push(adj[curr][i]);
            }
        }
        if(counter==N) return true;
        else return false;
    }
};