class Solution {
  private:
  bool recur(int index, int target,vector<int>&arr, vector<vector<int>>& dp){
      if(target==0) return true;
      if(dp[index][target]!=-1) return dp[index][target];
      if(index==0) return (arr[index]==target);
      
      bool notTake=recur(index-1,target,arr,dp);
      bool take=false;
      if(arr[index]<=target){
          take=recur(index-1,target-arr[index],arr,dp);
      }
      return dp[index][target]=take | notTake;
      
  }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int length=arr.size()-1;
        vector<vector<int>> dp(length+1,vector<int>(sum+1,-1));
        return recur(length,sum,arr,dp);
    }
};