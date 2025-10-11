class Solution {
private:
    int houseRobber(int idx, vector<int>& dp, vector<int>& nums){
        if(idx<0) return 0;
        else if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx] + houseRobber(idx-2,dp,nums);
        int nopick=0 + houseRobber(idx-1,dp,nums);
        return dp[idx]=max(pick,nopick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return houseRobber(n-1,dp,nums);
    }
};