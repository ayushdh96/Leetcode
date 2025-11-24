class Solution {
private:
    int recur(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        //base case
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for ( int k=i; k<=j;k++){
            int value= nums[i-1]*nums[k]*nums[j+1] + recur(i,k-1,nums,dp) + recur(k+1,j,nums,dp);
            maxi=max(maxi,value);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        //return recur(1,n-2,nums,dp);
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxi=INT_MIN;
                for ( int k=i; k<=j;k++){
                    int value= nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi=max(maxi,value);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n-2];
    }
};