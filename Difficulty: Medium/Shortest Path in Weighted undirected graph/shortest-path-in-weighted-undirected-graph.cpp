class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1,INT_MAX);
        distance[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int currNode=pq.top().second;
            int currDistance=pq.top().first;
            pq.pop();
            for(int i=0;i<adj[currNode].size();i++){
                int tempDistance=adj[currNode][i].second;
                int tempNode=adj[currNode][i].first;
                if(tempDistance+currDistance<distance[tempNode]){
                    pq.push({tempDistance+currDistance,tempNode});
                    distance[tempNode]=tempDistance+currDistance;
                    parent[tempNode]=currNode;
                }
            }
        }
        vector<int> ans;
        if(distance[n]==INT_MAX) return {-1};
        else{
            int Node=n,temp;
            while(Node!=1){
                ans.push_back(Node);
                Node=parent[Node];
            }
            ans.push_back(1);
            ans.push_back(distance[n]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};