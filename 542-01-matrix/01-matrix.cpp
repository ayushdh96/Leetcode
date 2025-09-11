class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> data(m,vector<int>(n));
        queue<pair<pair<int, int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int column=q.front().first.second;
            int travel=q.front().second;
            q.pop();
            if(row+1<m && vis[row+1][column]!=1){
                vis[row+1][column]=1;
                q.push({{row+1,column},travel+1});
                data[row+1][column]=travel+1;
            }
            if(row-1>=0 && vis[row-1][column]!=1){
                vis[row-1][column]=1;
                q.push({{row-1,column},travel+1});
                data[row-1][column]=travel+1;
            }
            if(column+1<n && vis[row][column+1]!=1){
                vis[row][column+1]=1;
                q.push({{row,column+1},travel+1});
                data[row][column+1]=travel+1;
            }
            if(column-1>=0 && vis[row][column-1]!=1){
                vis[row][column-1]=1;
                q.push({{row,column-1},travel+1});
                data[row][column-1]=travel+1;
            }
        }
    return data;
    }
};