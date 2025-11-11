class Solution {
private:
    int recur(int index1,int index2,string& s,string& t, vector<vector<int>>& dp){
        //base case
        if(index2==0) return 1;
        if(index1==0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1-1]==t[index2-1]){
            return dp[index1][index2]=recur(index1-1,index2-1,s,t,dp) + recur(index1-1,index2,s,t,dp);
        }
        return dp[index1][index2]=recur(index1-1,index2,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int length1=s.size();
        int length2=t.size();
        //vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        //return recur(length1,length2,s,t,dp);
        vector<vector<double>> dp(length1+1,vector<double>(length2+1,0));
        for(int i=0;i<=length1;i++) dp[i][0]=1;
        for(int index1=1;index1<=length1;index1++){
            for(int index2=1;index2<=length2;index2++){
                if(s[index1-1]==t[index2-1]) dp[index1][index2]=dp[index1-1][index2-1]+ dp[index1-1][index2];
        
         else dp[index1][index2]=dp[index1-1][index2];
            }
        }
    return (int)dp[length1][length2];
    }
    
};