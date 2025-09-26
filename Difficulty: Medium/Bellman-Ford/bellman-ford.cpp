// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> distance(V,1e8);
        bool flag=false;
        distance[src]=0;
        for(int i=1;i<V;i++){
            for(int j=0;j<edges.size();j++){
                int currNode=edges[j][0];
                int nextNode=edges[j][1];
                int nextCost=edges[j][2];
                if(distance[currNode]+nextCost < distance[nextNode] && distance[currNode]!=1e8) {
                    distance[nextNode]=distance[currNode]+nextCost;}
            }
        }
        for(int j=0;j<edges.size();j++){
                int currNode=edges[j][0];
                int nextNode=edges[j][1];
                int nextCost=edges[j][2];
                if(distance[currNode]+nextCost<distance[nextNode] && distance[currNode]!=1e8) {return {-1};}
            }
        return distance;
    }
};
