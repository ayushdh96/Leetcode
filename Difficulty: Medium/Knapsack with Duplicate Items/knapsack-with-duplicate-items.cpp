class Solution {
  private:
    int recur(int index, int target, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        
        if(target==0) return 0;
        if(index==0) {
            return val[index] * int(target/wt[0]);
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int noTake=recur(index-1,target,val,wt,dp);
        int take=-1e9;
        if(wt[index]<=target) take=val[index] + recur(index, target-wt[index], val, wt,dp);
        return dp[index][target]=max(noTake, take);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int length=val.size();
        vector<vector<int>> dp(length,vector<int>(capacity+1,-1));
        return recur(length-1,capacity,val,wt,dp);
    }
};