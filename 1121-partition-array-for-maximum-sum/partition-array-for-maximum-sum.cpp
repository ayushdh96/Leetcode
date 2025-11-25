class Solution {
private:
    int recur(int i,vector<int>& arr, int k, vector<int>& dp){
        //base case
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int length=0;
        int maxi=-1e9;
        int maxVal=-1e9;
        int loopCompare=min(i+k,(int)arr.size());
        for(int j=i;j<loopCompare;j++){
            length++;
            maxi=max(maxi,arr[j]);
            int sum=length*maxi + recur(j+1,arr,k,dp);
            maxVal=max(maxVal,sum);
        }
        return dp[i]=maxVal;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return recur(0,arr,k,dp);
    }
};