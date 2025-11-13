class Solution {
private:
    int recur(int index, int buy, int transaction, vector<int>& prices, vector<vector<vector<int>>>& dp){
        //base case
        if(transaction==0) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][transaction]!=-1) return dp[index][buy][transaction];
        if(buy==1){
            return dp[index][buy][transaction]= max(-prices[index] + recur(index+1,0,transaction,prices,dp), recur(index+1,1,transaction,prices,dp));
        }
        else{
            return dp[index][buy][transaction]=max(+prices[index] + recur(index+1,1,transaction-1,prices,dp),recur(index+1,0,transaction, prices,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int length=prices.size();
        vector<vector<vector<int>>> dp(length,vector<vector<int>>(2,vector<int>(3,-1)));
        return recur(0,1,2,prices,dp);
    }
};