class Solution {
  private:
    int recur(int i, int j, vector<int> &arr, vector<vector<int>> dp){
        //base case
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j-1;k++){
            int steps=arr[i-1]*arr[k]*arr[j] + recur(i,k,arr,dp) + 
            recur(k+1,j,arr,dp);
        
            if(steps<mini) mini=steps;
        }
        return dp[i][j]=mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        //vector<vector<int>> dp(n,vector<int>(n,-1));
        //return recur(1,arr.size()-1,arr,dp);
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k]+ 
                    dp[k+1][j];
                
                    if(steps<mini) mini=steps;
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};