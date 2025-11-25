// User function Template for C++
class Solution {
  private:
    int recur(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>>& dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(int k=i+1;k<=j-1;k=k+2){
            int  lT=recur(i,k-1,1,s,dp);
            int lF=recur(i,k-1,0,s,dp);
            int rT=recur(k+1,j,1,s,dp);
            int rF=recur(k+1,j,0,s,dp);
            if(s[k]=='&'){
                if(isTrue) ways=ways+(rT*lT);
                else ways=ways+(lT*rF) + (lF*rT) + (lF*rF);
            }
            else if(s[k]=='|'){
                if(isTrue) ways=ways+(lT*rT) + (lT*rF) + (lF*rT);
                else ways=ways+(lF*rF);
            }
            else if(s[k]=='^'){
                if(isTrue) ways=ways+(rT*lF) + (rF*lT);
                else ways=ways+(lT*rT)+(lF*rF);
            }
        }
        return dp[i][j][isTrue]=ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int n=s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return recur(0,s.size()-1,1,s,dp);
    }
};