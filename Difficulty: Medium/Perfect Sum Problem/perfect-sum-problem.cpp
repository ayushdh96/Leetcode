class Solution {
  private:
  int recur(int index, int target, vector<int>& arr, vector<vector<int>>& dp){
      if(index == 0){
          if(target == 0 && arr[0] == 0) return 2; // {} and {0}
          if(target == 0) return 1;               // only {}
          return (arr[0] == target) ? 1 : 0;      // {arr[0]} or none
      }

      if(dp[index][target] != -1) return dp[index][target];

      int noPick = recur(index - 1, target, arr, dp);
      int pick = 0;
      if(arr[index] <= target)
          pick = recur(index - 1, target - arr[index], arr, dp);

      return dp[index][target] = pick + noPick;
  }

  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return recur(n - 1, target, arr, dp);
    }
};