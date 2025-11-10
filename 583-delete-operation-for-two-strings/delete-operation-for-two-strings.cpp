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
    int minDistance(string word1, string word2) {
        int length1=word1.size();
        int length2=word2.size();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        int subCount=recur(length1,length2,word1,word2,dp);
        return (length1-subCount+length2-subCount);
    }
};