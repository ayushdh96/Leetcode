class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) {q.push(i);
            ans.push_back(i);
            }
        }
        
        int counter=0;
        while(!q.empty()){
            counter++;
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0) {
                    q.push(adj[curr][i]);
                    ans.push_back(adj[curr][i]);
                }
            }
        }
        if(counter==numCourses) return ans;
        else return {};
    }
};