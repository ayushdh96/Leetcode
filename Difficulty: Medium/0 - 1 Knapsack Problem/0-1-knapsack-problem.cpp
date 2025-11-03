class Solution {
  private:
  int recur(int index, int W, vector<int> &val, vector<int> &wt,vector<vector<int>>& dp){
      if(index==0){
          if(wt[0]<=W) return val[0];
          else return 0;
      }
      if(dp[index][W]!=-1) return dp[index][W];
      int noTake=0+recur(index-1,W,val,wt,dp);
      int take=-1e9;
      if(wt[index]<=W) take=val[index]+recur(index-1,W-wt[index],val,wt,dp);
      return dp[index][W]=max(noTake,take);
  }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int index=val.size();
        vector<vector<int>> dp(index,vector<int>((W+1),-1));
        return recur(index-1, W,val,wt,dp);
    }
};