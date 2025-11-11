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
        //vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        //return recur(length1,length2,word1,word2,dp);
        /**vector<vector<int>> dp(length1+1,vector<int>(length2+1,0));
        for(int i=0;i<=length1;i++) dp[i][0]=i;
        for(int i=0;i<=length2;i++) dp[0][i]=i;
        for(int index1=1;index1<=length1;index1++){
            for(int index2=1;index2<=length2;index2++){
                if(word1[index1-1]==word2[index2-1]) dp[index1][index2]=dp[index1-1][index2-1];
        
                else{
                    int minV=1e9;
                    int insert=1+dp[index1][index2-1];
                    int deleteC=1+dp[index1-1][index2];
                    int replace=1+dp[index1-1][index2-1];
                    minV=min(insert,replace);
                    dp[index1][index2]=min(deleteC,minV);
                }
            }
        }
        return dp[length1][length2];**/
        vector<int> curr(length2+1,0),prev(length2+1,0);
        for(int i=0;i<=length2;i++) prev[i]=i;
        for(int index1=1;index1<=length1;index1++){
            curr[0]=index1;
            for(int index2=1;index2<=length2;index2++){
                if(word1[index1-1]==word2[index2-1])curr[index2]=prev[index2-1];
        
                else{
                    int minV=1e9;
                    int insert=1+curr[index2-1];
                    int deleteC=1+prev[index2];
                    int replace=1+prev[index2-1];
                    minV=min(insert,replace);
                    curr[index2]=min(deleteC,minV);
                }
            }
            prev=curr;
        }
        return prev[length2];
    }
};