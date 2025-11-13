class Solution {
private:
    int recur(int index, int buy, int& fee, vector<int>& prices,vector<vector<int>>& dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy==1) return dp[index][buy]= max(-prices[index] + recur(index+1,0,fee,prices,dp), recur(index+1,1,fee,prices,dp));
        else return dp[index][buy]= max(-fee + prices[index] +recur(index+1,1,fee,prices,dp), recur(index+1,0,fee,prices,dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int length=prices.size();
        vector<vector<int>> dp(length+1,vector<int>(2,-1));
        return recur(0,1,fee,prices,dp);
    }
};