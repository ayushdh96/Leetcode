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
    string shortestCommonSupersequence(string str1, string str2) {
        int length1=str1.size();
        int length2=str2.size();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        int subSequence=recur(length1,length2,str1,str2,dp);
        string ans(length1+length2-subSequence,' ');
        int index1=length1;
        int index2=length2;
        int ansIndex=ans.length()-1;
        while(index1>0&& index2>0){
            if(str1[index1-1]==str2[index2-1]){
                ans[ansIndex]=str1[index1-1];
                index1--;
                index2--;
                ansIndex--;
                
            }
            else{
                if(dp[index1][index2]==dp[index1-1][index2]){
                    ans[ansIndex]=str1[index1-1];
                    index1--;
                    ansIndex--;
                }
                else{
                    ans[ansIndex]=str2[index2-1];
                    index2--;
                    ansIndex--;
                }
            }
        }
        while(index1>0){
            ans[ansIndex]=str1[index1-1];
            index1--;
            ansIndex--;
        }
        while(index2>0){
            ans[ansIndex]=str2[index2-1];
            index2--;
            ansIndex--;
        }
        return ans;
    }
};