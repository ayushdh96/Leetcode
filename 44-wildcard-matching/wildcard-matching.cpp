class Solution {
private:
    bool recur(int index1, int index2, string& s, string& p, vector<vector<int>>& dp){
        //base case
        if(index1==0 && index2==0) return true;
        if(index2==0) return false;
        if(index1==0 && index2>0){
            for(int i=0;i<=index2-1;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1-1]==p[index2-1] || p[index2-1]=='?') return dp[index1][index2]=recur(index1-1,index2-1,s,p,dp);
        else if(p[index2-1]=='*'){
            bool noConsider=recur(index1,index2-1,s,p,dp);
            bool stay=recur(index1-1,index2,s,p,dp);
            return dp[index1][index2]=(noConsider || stay);
        }
        else {
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int length1=s.size();
        int length2=p.size();
        //vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        //return recur(length1,length2,s,p,dp);
        vector<vector<bool>> dp(length1+1,vector<bool>(length2+1,0));
        dp[0][0]=1;
        int index2=1;
        while(p[index2-1]=='*' && index2<=length2){
            dp[0][index2]=1;
            index2++;
        }
        for(int index1=1;index1<=length1;index1++){
            for(int index2=1;index2<=length2;index2++){
                if(s[index1-1]==p[index2-1] || p[index2-1]=='?') dp[index1][index2]=dp[index1-1][index2-1];
                else if(p[index2-1]=='*'){
                    bool noConsider=dp[index1][index2-1];
                    bool stay=dp[index1-1][index2];
                    dp[index1][index2]=(noConsider || stay);
                }
                else{dp[index1][index2]= false; }
            }
        }
        return dp[length1][length2];
    }
};