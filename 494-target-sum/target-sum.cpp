class Solution {
private:
    int recur(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(index==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0) return 1;
            if(nums[0]==target) return 1;
            else return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int noPick=recur(index-1,target,nums,dp);
        int pick=0;
        if(nums[index]<=target) pick=recur(index-1,target-nums[index],nums,dp);
        return dp[index][target]=pick+noPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int length=nums.size();
        int totalSum=0;
        for(int i=0;i<length;i++){
            totalSum=totalSum+nums[i];
        }
        target=abs(target);
        if((totalSum-target)%2!=0 || totalSum-target<0) return 0;

        //vector<vector<int>> dp(length,vector<int>(totalSum+1,-1));
        //return recur(length-1,(totalSum-target)/2,nums,dp);
        vector<vector<int>> dp(length,vector<int>(totalSum+1,0));
        if (nums[0] == 0) dp[0][0] = 2;                // +0 or -0
    else {
        dp[0][0] = 1;                              // don't take first
        if (nums[0] <= (totalSum-target)/2) dp[0][nums[0]] = 1;      // take first
    }
        for(int index=1;index<length;index++){
            for(int t=0;t<=(totalSum-target)/2;t++){
                int noPick=dp[index-1][t];
                int pick=0;
                if(nums[index]<=t) pick=dp[index-1][t-nums[index]];
                dp[index][t]=pick+noPick;
            }
        }
        return dp[length-1][(totalSum-target)/2];


    }
};