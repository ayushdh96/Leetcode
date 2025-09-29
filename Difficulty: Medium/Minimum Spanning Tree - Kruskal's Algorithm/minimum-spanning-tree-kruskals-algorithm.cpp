// User function Template for C++
class Disjoint{
    vector<int> size,parent;
    public:
    Disjoint(int v){
        size.resize(v,1);
        parent.resize(v,0);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]){
            return parent[node];
        }
        else return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int left, int right){
        int leftParent=findParent(left);
        int rightParent=findParent(right);
        if(leftParent==rightParent) return;
        else if(size[leftParent]>size[rightParent]){
            parent[rightParent]=leftParent;
            size[leftParent]+=size[rightParent];
            
        }
        else {
            parent[leftParent]=rightParent;
            size[rightParent]+=size[leftParent];
            
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            adj.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        }
        sort(adj.begin(),adj.end());
        
        Disjoint ds(V);
        int mstWeight=0;
        for(int i=0;i<adj.size();i++){
            int first=adj[i].second.first;
            int second=adj[i].second.second;
            int weight=adj[i].first;
            if(ds.findParent(first)!=ds.findParent(second)){
                mstWeight+=weight;
                ds.unionBySize(first,second);
            }
        }
        return mstWeight;
    }
};