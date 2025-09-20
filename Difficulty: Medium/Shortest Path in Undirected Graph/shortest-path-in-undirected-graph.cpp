class Solution {
  private:
    
    
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int m= adj.size();
        int n= adj[0].size();
        vector<int> vis(m,0);
        vector<int> dis(m,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        dis[src]=0;
        vis[src]=1;
        while(!q.empty()){
            int currNode=q.front().first;
            int currDistance=q.front().second;
            q.pop();
            for(int i=0;i<adj[currNode].size();i++){
                if(dis[adj[currNode][i]]>currDistance+1){
                    dis[adj[currNode][i]]=currDistance+1;
                    q.push({adj[currNode][i],currDistance+1});
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};