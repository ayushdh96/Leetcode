class Solution {
private:
    void bfs(int m, int n, vector<vector<char>> &vis, vector<vector<char>> &grid, int i, int j){
        vis[i][j] = '1';
        queue<pair<int,int>> q;
        q.push({i, j});

        // 4 possible directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int mrow = q.front().first;
            int ncol = q.front().second;
            q.pop();

            for(auto dir : directions){
                int newRow = mrow + dir.first;
                int newCol = ncol + dir.second;

                if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && 
                   vis[newRow][newCol] == '0' && grid[newRow][newCol] == '1'){
                    vis[newRow][newCol] = '1';
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<char>> vis(m, vector<char>(n, '0'));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && vis[i][j] == '0'){
                    count++;
                    bfs(m, n, vis, grid, i, j);
                }
            }
        }
        return count;
    }
};