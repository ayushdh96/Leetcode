class Solution {
private:
    int recur(int index1,int index2,string& text1, string& text2, vector<vector<int>>& dp){
        if(index1==0 || index2==0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(text1[index1-1]==text2[index2-1]) return dp[index1][index2]=1+recur(index1-1,index2-1,text1,text2,dp);
        else{
            int left=recur(index1-1,index2,text1,text2,dp);
            int right=recur(index1,index2-1,text1,text2,dp);
            return dp[index1][index2]=max(left,right);
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1=text1.size();
        int length2=text2.size();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        return recur(length1,length2,text1,text2,dp);
    }
};