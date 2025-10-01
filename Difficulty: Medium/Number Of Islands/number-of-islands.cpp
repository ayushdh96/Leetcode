// User function Template for C++
class Disjoint{
    vector<int> size,parent;
    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        Disjoint dj(n*m);
        vector<int> ans;
        int count=0;
        for(int i=0;i<operators.size();i++){
            int djNodeLoc=operators[i][0]*m+operators[i][1];
            int row=operators[i][0];
            int col=operators[i][1];
            if(vis[row][col]==1) {
                ans.push_back(count);
                continue;
                
            }
            count++;
            vis[row][col]=1;
            if(row-1>=0 && vis[row-1][col]==1 && dj.findParent(djNodeLoc)!=dj.findParent((row-1)*m + col)){
                
                    dj.unionBySize(djNodeLoc,(row-1)*m+col);
                    count--;
                
            }
            if(row+1<n && vis[row+1][col]==1 && dj.findParent(djNodeLoc)!=dj.findParent((row+1)*m + col)){
                
                    dj.unionBySize(djNodeLoc,(row+1)*m+col);
                    count--;
                
            }
            if(col-1>=0 && vis[row][col-1]==1 && dj.findParent(djNodeLoc)!=dj.findParent((row)*m + col-1)){
                
                    dj.unionBySize(djNodeLoc,(row)*m+ col - 1);
                    count--;
                
            }
            if(col+1<m && vis[row][col+1]==1 && dj.findParent(djNodeLoc)!=dj.findParent((row)*m + col+1)){
                
                    dj.unionBySize(djNodeLoc,(row)*m + col + 1);
                    count--;
                
            }
            ans.push_back(count);
        }
     return ans;   
    }
};
