class Solution {
  private:
  int dpRecurr(int stairNo, vector<int>& height, vector<int>& dp){
      if(stairNo==0) return 0;
      if(dp[stairNo]!=-1) return dp[stairNo];
      int left= dpRecurr(stairNo-1,height,dp) + abs(height[stairNo]-height[stairNo-1]);
      int right=INT_MAX;
      if(stairNo>=2) right=dpRecurr(stairNo-2,height,dp) + abs(height[stairNo]-height[stairNo-2]);
      return dp[stairNo] = min(left,right);
      
  }
  public:
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size(),-1);
        return dpRecurr(height.size()-1,height,dp);
    }
};