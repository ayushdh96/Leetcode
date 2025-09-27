class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int leastCityCount=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            vector<int> dist(n,INT_MAX);
            dist[i]=0;
            pq.push({0,i});
            int count=0;
            while(!pq.empty()){
                int currDistance=pq.top().first;
                int currNode=pq.top().second;
                pq.pop();
                for(int j=0;j<adj[currNode].size();j++){
                    int nextNode=adj[currNode][j].first;
                    int nextWeight=adj[currNode][j].second;
                    if(currDistance+nextWeight<dist[nextNode] && currDistance+nextWeight<=distanceThreshold){
                        cout<<nextNode<<" "<<currDistance+nextWeight<<"yas"<<"\n";
                        if(dist[nextNode]==INT_MAX) count++;
                        dist[nextNode]=currDistance+nextWeight;
                        pq.push({currDistance+nextWeight,nextNode});
                    }
                }
            }
            cout<<count<<" "<<i<<"\n";
            if(count<=leastCityCount) {
                ans=i;
                leastCityCount=count;
                }
        }
        return ans;
        }
};