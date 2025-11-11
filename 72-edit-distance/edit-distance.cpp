class Solution {
private:
    int recur(int index1,int index2, string& word1, string& word2, vector<vector<int>>& dp){
        //Base case
        if(index1==0) return index2;
        if(index2==0) return index1;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(word1[index1-1]==word2[index2-1]) return dp[index1][index2]=recur(index1-1,index2-1,word1,word2,dp);
        
        else{
            int minV=1e9;
            int insert=1+recur(index1,index2-1,word1,word2,dp);
            int deleteC=1+recur(index1-1,index2,word1,word2,dp);
            int replace=1+recur(index1-1,index2-1,word1,word2,dp);
            minV=min(insert,replace);
            return dp[index1][index2]=min(deleteC,minV);
        }
    }
public:
    int minDistance(string word1, string word2) {
        int length1=word1.size();
        int length2=word2.size();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        return recur(length1,length2,word1,word2,dp);
    }
};