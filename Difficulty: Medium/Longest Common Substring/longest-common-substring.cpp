class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int length1=s1.size();
        int length2=s2.size();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,0));
        int ans=0;
        for(int index1=1;index1<=length1;index1++){
            for(int index2=1;index2<=length2;index2++){
                if(s1[index1-1]==s2[index2-1]){
                    dp[index1][index2]=1+dp[index1-1][index2-1];
                    ans=max(ans,dp[index1][index2]);
                }
                else{
                    dp[index1][index2]=0;
                }
            }
        }
        return ans;
    }
};