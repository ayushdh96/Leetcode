class Disjoint{
    public:
    vector<int> size,parent;
    int extraCount=0;
    Disjoint(int v){
        parent.resize(v);
        size.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]){
            return parent[node];
        }
        return parent[node]=findParent(parent[node]);
        
    }
    void unionBySize(int left, int right){
        int leftParent=findParent(left);
        int rightParent=findParent(right);
        if(leftParent==rightParent){
            extraCount++;
            return;
        }
        if(size[leftParent]<size[rightParent]){
            size[rightParent]+=size[leftParent];
            parent[leftParent]=parent[rightParent];
        }
        else{
            size[leftParent]+=size[rightParent];
            parent[rightParent]=parent[leftParent];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint dj(n);
        for(int i=0;i<connections.size();i++){
            dj.unionBySize(connections[i][0],connections[i][1]);
        }
        int unique=0;
        for(int i=0;i<n;i++){
            if(dj.parent[i]==i) unique++;
        }
        if(dj.extraCount+1>=unique) return unique-1;
        else return -1;
    }
};