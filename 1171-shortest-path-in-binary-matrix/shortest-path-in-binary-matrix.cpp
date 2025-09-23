class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        if(grid.size()==0){
      return -1;
      }
    if(grid[0][0]==1) return -1;
    if(n==1) return 1;
    distance[0][0]=0;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    while(!q.empty()){
        int currDis=q.front().first;
        int currRow=q.front().second.first;
        int currCol=q.front().second.second;
        q.pop();
        if(n>currRow+1 && currDis+1<distance[currRow+1][currCol]&& grid[currRow+1][currCol]==0){
            if(currRow+1 ==n-1 && currCol == n-1) return currDis+2;
            q.push({currDis+1,{currRow+1,currCol}});
            distance[currRow+1][currCol]=currDis+1;
        }
        if(currRow-1>=0 && currDis+1<distance[currRow-1][currCol] && grid[currRow-1][currCol]==0){
            if(currRow-1 ==n-1 && currCol == n-1) return currDis+2;
            q.push({currDis+1,{currRow-1,currCol}});
            distance[currRow-1][currCol]=currDis+1;
        }
        if(n>currCol+1 && currDis+1<distance[currRow][currCol+1]&& grid[currRow][currCol+1]==0) {
            if(currRow ==n-1 && currCol+1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow,currCol+1}});
            distance[currRow][currCol+1]=currDis+1;
        }
        if(currCol-1>=0 && currDis+1<distance[currRow][currCol-1] && grid[currRow][currCol-1]==0){
            if(currRow ==n-1 && currCol-1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow,currCol-1}});
            distance[currRow][currCol-1]=currDis+1;
        }
        //
        if(n>currRow+1 && n>currCol+1 && currDis+1<distance[currRow+1][currCol+1]&& grid[currRow+1][currCol+1]==0){
            if(currRow+1 ==n-1 && currCol+1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow+1,currCol+1}});
            distance[currRow+1][currCol+1]=currDis+1;
        }
        if(currRow-1>=0 && currCol-1>=0 && currDis+1<distance[currRow-1][currCol-1] && grid[currRow-1][currCol-1]==0){
            if(currRow-1 ==n-1 && currCol-1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow-1,currCol-1}});
            distance[currRow-1][currCol-1]=currDis+1;
        }
        if(n>currCol+1 && currRow-1>=0  && currDis+1<distance[currRow-1][currCol+1]&& grid[currRow-1][currCol+1]==0) {
            if(currRow-1 ==n-1 && currCol+1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow-1,currCol+1}});
            distance[currRow-1][currCol+1]=currDis+1;
        }
        if(currCol-1>=0 && n>currRow+1 && currDis+1<distance[currRow+1][currCol-1] && grid[currRow+1][currCol-1]==0){
            if(currRow+1 ==n-1 && currCol-1 == n-1) return currDis+2;
            q.push({currDis+1,{currRow+1,currCol-1}});
            distance[currRow+1][currCol-1]=currDis+1;
        }
    }
    return -1;
    }

};