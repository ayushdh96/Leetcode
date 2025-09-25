class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int row=heights.size();
        int col=heights[0].size();
        if(row==col && row==1) return 0;
        pq.push({0,{0,0}});
        vector<vector<int>> diff(row,vector<int>(col,INT_MAX));
        diff[0][0]=0;
        while(!pq.empty()){
            int currDist=pq.top().first;
            int currRow=pq.top().second.first;
            int currCol=pq.top().second.second;
            int currHeight=heights[currRow][currCol];
            if(pq.top().second.first==row-1 && pq.top().second.second==col-1){
                    return pq.top().first;
                }
            pq.pop();
            if(currRow+1<row && abs(heights[currRow+1][currCol]-currHeight)<diff[currRow+1][currCol]){
                pq.push({max(currDist,abs(heights[currRow+1][currCol]-currHeight)),{currRow+1,currCol}});
                diff[currRow+1][currCol]=abs(heights[currRow+1][currCol]-currHeight);
                
            }
            if(currRow-1>=0 && abs(heights[currRow-1][currCol]-currHeight)<diff[currRow-1][currCol]){
                pq.push({max(currDist,abs(heights[currRow-1][currCol]-currHeight)),{currRow-1,currCol}});
                diff[currRow-1][currCol]=abs(heights[currRow-1][currCol]-currHeight);
                
                
            }
            if(currCol+1<col && abs(heights[currRow][currCol+1]-currHeight)<diff[currRow][currCol+1]){
                pq.push({max(currDist,abs(heights[currRow][currCol+1]-currHeight)),{currRow,currCol+1}});
                diff[currRow][currCol+1]=abs(heights[currRow][currCol+1]-currHeight);
            }
            if(currCol-1>=0 && abs(heights[currRow][currCol-1]-currHeight)<diff[currRow][currCol-1]){
                pq.push({max(currDist,abs(heights[currRow][currCol-1]-currHeight)),{currRow,currCol-1}});
                diff[currRow][currCol-1]=abs(heights[currRow][currCol-1]-currHeight);
            }
        }

return diff[row-1][col-1];
    }
};