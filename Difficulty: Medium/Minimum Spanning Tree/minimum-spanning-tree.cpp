class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < (int)edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> vis(V, 0);
        pq.push({0, 0});
        long long sum = 0; // safer if weights can be big

        while (!pq.empty()) {
            auto [currWeight, currNode] = pq.top();
            pq.pop();
            if (vis[currNode]) continue;

            vis[currNode] = 1;
            sum += currWeight;

            for (auto &p : adj[currNode]) {
                int nextNode = p.first, nextWeight = p.second;
                if (!vis[nextNode]) pq.push({nextWeight, nextNode});
            }
        }
        return (int)sum; // or change signature to long long if allowed
    }
};