class Solution {
private:
    int recur(int index, int prev, vector<int>& nums, vector<vector<int>>& dp){
        //base case
        if(index==nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int length=recur(index+1,prev,nums,dp);
        if(prev==-1 || nums[index]>nums[prev]){
            return dp[index][prev+1]=max(length, 1+recur(index+1,index,nums,dp));
        }
        return dp[index][prev+1]=length;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return recur(0,-1,nums,dp);
    }
};