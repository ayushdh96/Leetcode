// User function Template for C++

class Solution {
  private:
  int recur(int index,int target, vector<int>& price , vector<vector<int>>& dp){
      if(index==0){
          return target*price[index];
      }
      if(dp[index][target]!=-1) return dp[index][target];
      int noTake=0+recur(index-1, target, price,dp);
      int take=-1e9;
      int rodLength=index+1;
      if(rodLength<=target) take=price[index]+recur(index,target-rodLength,price,dp);
      return dp[index][target]=max(take,noTake);
  }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int length=price.size();
        vector<vector<int>> dp(length,vector<int>(length+1,-1)); 
        return recur(length-1,length,price,dp);
    }
};