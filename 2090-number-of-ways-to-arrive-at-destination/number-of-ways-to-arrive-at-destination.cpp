class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> time(n,LLONG_MAX), ways(n,0);
        int minTime=INT_MAX;
        time[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            long long currTime=pq.top().first;
            long long currNode=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[currNode].size();i++){
                int adjNode=adj[currNode][i].first;
                int adjTime=adj[currNode][i].second;
                if((long long)adjTime+currTime<=(long long)time[adjNode]){
                    if((long long)adjTime+currTime<time[adjNode]){
                    time[adjNode]=(long long)adjTime+currTime;
                    pq.push({(long long)adjTime+currTime,adjNode});
                    ways[adjNode]=ways[currNode];
                    }
                    else{
                        ways[adjNode]=(ways[currNode]+ways[adjNode])%mod;
                    }
                }
            }
        }
        return ways[n-1]%mod;
    }
};