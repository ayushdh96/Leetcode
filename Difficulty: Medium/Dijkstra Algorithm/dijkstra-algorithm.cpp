// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> distance(V,INT_MAX);
        distance[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        int tempNode;
        int tempDistance;
        while(!pq.empty()){
            int currNode=pq.top().second;
            int currDist=pq.top().first;
            pq.pop();
            int m=adj[currNode].size();
            for(int i=0;i<m;i++){
                tempNode=adj[currNode][i].first;
                tempDistance=adj[currNode][i].second;
                if(distance[tempNode]>currDist+tempDistance){
                    pq.push({tempDistance+currDist,tempNode});
                    distance[tempNode]=currDist+tempDistance;
                }
            }
        }
        return distance;
    }
};