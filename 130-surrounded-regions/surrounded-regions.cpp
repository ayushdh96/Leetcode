class Solution {
private:
void dfs(pair<int,int> node, vector<vector<int>>& vis, vector<vector<char>>& board){
    int row=node.first;
    int col=node.second;
    int m=vis.size();
    int n=vis[0].size();
    vis[row][col]=1;
    if(row-1>=0 && vis[row-1][col]==0 && board[row-1][col]=='O'){
        dfs({row-1,col},vis,board);
    }
    if(row+1<m && vis[row+1][col]==0 && board[row+1][col]=='O'){
        dfs({row+1,col},vis,board);
    }
    if(col-1>=0 && vis[row][col-1]==0 && board[row][col-1]=='O'){
        dfs({row,col-1},vis,board);
    }
    if(col+1<n && vis[row][col+1]==0 && board[row][col+1]=='O'){
        dfs({row,col+1},vis,board);
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(vis[0][j]==0 && board[0][j]=='O'){
                dfs({0,j},vis,board);
            }
            if(m>0 && vis[m-1][j]==0 && board[m-1][j]=='O') dfs({m-1,j},vis,board);
        }
        for(int j=0;j<m;j++){
            if(vis[j][0]==0 && board[j][0]=='O') dfs({j,0},vis,board);
            if(n>0 && vis[j][n-1]==0 && board[j][n-1]=='O') dfs({j,n-1},vis,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};