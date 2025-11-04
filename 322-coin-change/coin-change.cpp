class Solution {
private:
    int recur( int index, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(index==0){
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int noTake=recur(index-1,target,coins,dp);
        int take=1e9;
        if(coins[index]<=target) take=1+recur(index,target-coins[index],coins,dp);
        return dp[index][target]=min(take,noTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int length=coins.size();
        //vector<vector<int>> dp(length,vector<int>(amount+1,-1));
        //int ans=recur(length-1,amount,coins,dp);
        //if (ans>amount) return -1;
        //else return ans;
        vector<vector<int>> dp(length,vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
        }
        for(int index=1;index<length;index++){
            for(int target=0;target<=amount;target++){
                int noTake=dp[index-1][target];
                int take=1e9;
                if(coins[index]<=target) take=1+dp[index][target-coins[index]];
                dp[index][target]=min(take,noTake);
            }
        }
        if (dp[length-1][amount]>amount) return -1;
        else return dp[length-1][amount];
    }
};