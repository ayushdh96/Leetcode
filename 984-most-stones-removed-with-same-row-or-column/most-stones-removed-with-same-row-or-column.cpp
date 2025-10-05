// User function Template for C++
class Disjoint{
    
    public:
    vector<int> size,parent;
    Disjoint(int v){
        parent.resize(v);
        size.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
            size[i]=1;
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
    int removeStones(vector<vector<int>>& stones) {
        int rowMax=0;
        int colMax=0;
        int n=0;
        for(auto it:stones){
            n++;
            rowMax=max(rowMax,it[0]);
            colMax=max(colMax,it[1]);
        }
        Disjoint dj(rowMax+colMax+2);
        unordered_set<int> st;
        for(auto it:stones){
            dj.unionBySize(it[0],rowMax + it[1] + 1);
            st.insert(it[0]);
            st.insert(it[1] + rowMax + 1);
        }
        int count=0;
        for(auto it: st){
            if(dj.parent[it]==it) count++;
        }
        return n-count;
    }
};