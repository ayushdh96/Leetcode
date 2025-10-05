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
    bool isValid(int newr, int newc, int n){
        if(newr>=0 && newr<n && newc>=0 && newc<n){
            return true;
        }
        return false;
    } 
    int largestIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int m=grid.size();
        Disjoint dj(m*m);
        int max_value=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                for(int mov=0;mov<4;mov++){
                    int newr=i+dr[mov];
                    int newc=j+dc[mov];
                    if(isValid(newr,newc,m) && grid[newr][newc]==1){
                        int adjnode= newr*m + newc;
                        dj.unionBySize(adjnode, (i*m)+j);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
                set<int> components;
                for(int mov=0;mov<4;mov++){
                    int newr=i+dr[mov];
                    int newc=j+dc[mov];
                    if(isValid(newr,newc,m) && grid[newr][newc]==1){
                        components.insert(dj.findParent((newr*m)+newc));
                    }
                }
            int val=0;
            for(auto it : components){
                val=val+dj.size[it];
            }
            if(val+1>max_value){
                max_value=val+1;
            }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                max_value=max(max_value,dj.size[dj.findParent((i*m)+j)]);
            }
        }
        return max_value;
    }
};