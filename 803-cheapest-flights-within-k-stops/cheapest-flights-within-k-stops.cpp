class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int fromFlight=flights[i][0];
            int toFlight=flights[i][1];
            int cost=flights[i][2];
            adj[fromFlight].push_back({toFlight,cost});
        }
        distance[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int currNode=q.front().second.first;
            int currDist=q.front().second.second;
            q.pop();
            for(int i=0;i<adj[currNode].size();i++){
                int nextFlightDistance=currDist+adj[currNode][i].second;
                int nextFlightStop=stops+1;
                int nextFlight=adj[currNode][i].first;
                if(nextFlightDistance<distance[nextFlight] && (nextFlightStop<=k || nextFlight==dst && nextFlightStop<=k+1)){
                    q.push({nextFlightStop,{nextFlight,nextFlightDistance}});
                    distance[nextFlight]=nextFlightDistance;
                }
            }
        }
        if(distance[dst]==INT_MAX) return -1;
        else return distance[dst];
    }
};