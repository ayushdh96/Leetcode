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
        //vector<vector<vector<int>>> dp(length+1,vector<vector<int>>(2,vector<int>(2,-1)));
        //return recur(0,1,0,prices,dp);
        vector<vector<vector<int>>> dp(length+1,vector<vector<int>>(2,vector<int>(2,0)));
        for(int index=length-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cool=0;cool<=1;cool++){
                    if(buy==1){
                        if(cool==0)  dp[index][buy][cool]= max(-prices[index] + dp[index+1][0][0], dp[index+1][1][0]);
                        else  dp[index][buy][cool]= dp[index+1][1][0];
                    }
                    else{
                        dp[index][buy][cool]= max(+prices[index] + dp[index+1][1][1], dp[index+1][0][0]);
                    }
                }
            }
        }
        return max (dp[0][1][1],dp[0][1][0]);
    }
};