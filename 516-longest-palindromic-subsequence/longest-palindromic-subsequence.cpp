class Solution {
private:
    int recur(int index1, int index2,string& s, string& s2, vector<vector<int>>& dp){
        if(index1==0 || index2==0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1-1]==s2[index2-1]) return dp[index1][index2]=1 + recur(index1-1,index2-1,s,s2,dp);
        else{
            int left=recur(index1-1,index2,s,s2,dp);
            int right=recur(index1,index2-1,s,s2,dp);
            return dp[index1][index2]=max(left,right);
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int length1=s.size();
        string s2(length1,' ');
        for(int i=length1-1;i>=0;i--) s2[length1-1-i]=s[i];
        //vector<vector<int>> dp(length1+1,vector<int>(length1+1,-1));
        //return recur(length1,length1,s,s2,dp);
        vector<vector<int>> dp(length1+1,vector<int>(length1+1,0));
        for(int index1=1;index1<=length1;index1++){
            for(int index2=1;index2<=length1;index2++){
                if(s[index1-1]==s2[index2-1]) dp[index1][index2]= 1 + dp[index1-1][index2-1];
                else{
                    int left=dp[index1-1][index2];
                    int right=dp[index1][index2-1];
                    dp[index1][index2]=max(left,right);
                }
            }
        }
        return dp[length1][length1];
    }
};