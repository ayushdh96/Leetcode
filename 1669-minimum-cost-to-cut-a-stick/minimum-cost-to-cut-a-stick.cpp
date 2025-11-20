class Solution {
private:
    int recur(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k <= j; k++){
            int cost = cuts[j+1] - cuts[i-1]
                     + recur(i, k-1, cuts, dp)
                     + recur(k+1, j, cuts, dp);
            if(mini > cost) mini = cost;
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int origSize = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();  // m = origSize + 2

        // ----- TOP-DOWN (works) -----
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return recur(1, m-2, cuts, dp_rec);

        // ----- BOTTOM-UP (fixed) -----
        vector<vector<int>> dp(m, vector<int>(m, 0)); // use m, not origSize+1

        for(int i = origSize; i >= 1; i--){          // i: from m-2 down to 1
            for(int j = i; j <= origSize; j++){      // j: from i up to m-2
                int mini = 1e9;
                for(int k = i; k <= j; k++){
                    int cost = cuts[j+1] - cuts[i-1]
                             + dp[i][k-1]
                             + dp[k+1][j];
                    if(mini > cost) mini = cost;
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m-2];
    }
};