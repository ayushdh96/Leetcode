class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            dist[i][i]=0;
            pq.push({0,i});
            while(!pq.empty()){
                int currDistance=pq.top().first;
                int currNode=pq.top().second;
                pq.pop();
                for(int j=0;j<adj[currNode].size();j++){
                    int nextNode=adj[currNode][j].first;
                    int nextWeight=adj[currNode][j].second;
                    if(currDistance+nextWeight<dist[i][nextNode]){
                        dist[i][nextNode]=currDistance+nextWeight;
                        pq.push({currDistance+nextWeight,nextNode});
                    }
                }
            }
        }
            int leastCityCount=INT_MAX;
            int ans;
            for(int i=0;i<n;i++){
                int currentCityCount=0;
                for(int j=0;j<n;j++){
                    if(dist[i][j]<=distanceThreshold && i!=j) currentCityCount++;
                }
                if(currentCityCount<=leastCityCount){
                    ans=i; 
                    leastCityCount=currentCityCount;}
            }
        return ans;
        }
};