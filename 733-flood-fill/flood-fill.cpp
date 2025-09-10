class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int currValue=image[sr][sc];
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int n=q.front().first;
            int m=q.front().second;
            q.pop();
            if(n-1>=0 && image[n-1][m]!=color && image[n-1][m]==currValue){
              q.push({n-1,m});
              image[n-1][m]=color;
          }
          if(n+1<image.size() && image[n+1][m]!=color && image[n+1][m]==currValue){
              q.push({n+1,m});
              image[n+1][m]=color;
          }
          if(m-1>=0 && image[n][m-1]!=color && image[n][m-1]==currValue){
              q.push({n,m-1});
              image[n][m-1]=color;
          }
          if(m+1<image[n].size() && image[n][m+1]!=color && image[n][m+1]==currValue){
              q.push({n,m+1});
              image[n][m+1]=color;
          }
        }
    return image;
    }
};