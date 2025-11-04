class Solution {
private:
int recur(int index, int target, vector<int>& coins, vector<vector<int>>& dp){
    if(target==0) return 1;
    if(index==0) return (target%coins[0]==0);
    if(dp[index][target]!=-1) return dp[index][target];
    int noPick=recur(index-1, target,coins,dp);
    int pick=0;
    if(coins[index]<=target) pick=recur(index,target-coins[index],coins,dp);
    return dp[index][target]=pick+noPick;
}
public:
    int change(int amount, vector<int>& coins) {
        int length=coins.size();
        vector<vector<int>> dp(length,vector<int>(amount+1,-1));
        return recur(length-1,amount,coins,dp);
        
    }
};