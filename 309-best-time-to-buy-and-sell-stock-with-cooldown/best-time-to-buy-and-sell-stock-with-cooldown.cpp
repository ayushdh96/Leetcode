class Solution {
private:
    int recur(int index, int buy, int cool, vector<int>& prices, vector<vector<vector<int>>>& dp){
        //base case
        if(index==prices.size()) return 0;
        if(dp[index][buy][cool]!=-1) return dp[index][buy][cool];
        if(buy==1){
            if(cool==0) return dp[index][buy][cool]= max(-prices[index] + recur(index+1,0,0,prices,dp), recur(index+1,1,0,prices,dp));
            else  return dp[index][buy][cool]= recur(index+1,1,0,prices,dp);
        }
        else{
            return dp[index][buy][cool]= max(+prices[index] + recur(index+1,1,1,prices,dp), recur(index+1,0,0,prices,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int length=prices.size();
        vector<vector<vector<int>>> dp(length+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return recur(0,1,0,prices,dp);
    }
};