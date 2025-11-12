class Solution {
private:
    int recur(int index, int take, vector<int>& prices, vector<vector<int>>& dp){
        //base case
        if(index==prices.size()) return 0;
        if(dp[index][take]!=-1) return dp[index][take];
        if(take==1) {
             int profit=max(-prices[index] + recur(index+1,0,prices,dp), recur(index+1,1,prices,dp));
            return dp[index][take]=profit;
        }
        else {

         int profit= max(prices[index]+recur(index+1,1,prices,dp), recur(index+1,0,prices,dp));
         return dp[index][take]=profit;
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        //vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        //return recur(0,1,prices,dp);
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[prices.size()-1][0] = prices[prices.size()-1];
        for(int index=prices.size()-2;index>=0;index--){
            for(int j=0;j<2;j++){
               if(j==1) {
                    int profit=max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                    dp[index][j]=profit;
                }
                else {

                int profit= max(prices[index]+dp[index+1][1], dp[index+1][0]);
                dp[index][j]=profit;
        } 
            }
        }
        return dp[0][1];
    }
};