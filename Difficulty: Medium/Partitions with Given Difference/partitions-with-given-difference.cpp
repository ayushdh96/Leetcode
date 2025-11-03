class Solution {
  private:
  int recur(int index,int target,vector<int>& arr,vector<vector<int>>& dp){
      if(index == 0){
          if(target == 0 && arr[0] == 0) return 2; // {} and {0}
          if(target == 0) return 1;               // only {}
          return (arr[0] == target) ? 1 : 0;      // {arr[0]} or none
      }
      
      int nopick=recur(index-1,target,arr,dp);
      int pick=0;
      if(arr[index]<=target) pick=recur(index-1,target-arr[index],arr,dp);
      return dp[index][target]=pick+nopick;
  }
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum=0;
        for(int i=0;i<arr.size();i++){
            totalSum+=arr[i];
        }
        vector<vector<int>> dp(arr.size(),vector<int>(totalSum+1,0));
        int countleft=(totalSum-d)/2;
        if(countleft<0) return 0;
        if((totalSum-d)%2!=0) return 0;
        //return recur(arr.size()-1,countleft,arr,dp);
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0]<=countleft) dp[0][arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<=countleft;j++){
                int nopick=dp[i-1][j];
                  int pick=0;
                  if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
                  dp[i][j]=pick+nopick;
            }
        }
        return dp[arr.size()-1][countleft];
        
    }
};