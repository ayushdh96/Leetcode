class Solution {
  private:
    int geekTraining(int idx,vector<vector<int>>& dp,vector<vector<int>>& arr,int parent){
        if(idx<0) return 0;
        if(dp[idx][parent]!=-1) return dp[idx][parent];
        vector<int> temp(3,-1);
        int max=INT_MIN;
        for(int i=0;i<3;i++){
            if(parent!=i){
                temp[i]=arr[idx][i] + geekTraining(idx-1,dp,arr,i);
            }
            if(max<temp[i] && temp[i]!=-1){
                max=temp[i];
            }
        }
        return dp[idx][parent]=max;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> dp(arr.size(),vector<int>(4,-1));
        return geekTraining(arr.size()-1,dp,arr,3);
        
    }
};