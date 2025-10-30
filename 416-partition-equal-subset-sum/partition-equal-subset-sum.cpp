class Solution {
private:
bool recur(int index,int target,vector<int>& nums, vector<vector<int>>& dp){
    if(index==0) return nums[0]==target;
    if(dp[index][target]!=-1) return dp[index][target];
    if(target==0) return true;
    bool noTake=recur(index-1,target,nums,dp);
    bool take=false;
    if(nums[index]<=target) take=recur(index-1,target-nums[index],nums,dp);
    return dp[index][target]=take | noTake;
}
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int length=nums.size();
        
        for(int i=0;i<length;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0) return false;
        int target=totalSum/2;
        vector<vector<int>> dp(length,vector<int>(target+1,-1));
        return recur(length-1, target,nums,dp);
    }
};