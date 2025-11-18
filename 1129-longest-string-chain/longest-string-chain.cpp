class Solution {
private:
 bool compareStr(string prev, string curr){
    if (curr.size() != prev.size() + 1) return false;
    int indexPrev=0;
    int indexCurr=0;
    while(indexPrev!=prev.size() && indexCurr!=curr.size()){
        if(prev[indexPrev]==curr[indexCurr]){
            indexPrev++;
            indexCurr++;
        }
        else{
            indexCurr++;
        }
    }
    return indexPrev == prev.size();
 }
    
public:
    static bool comp(string& s1, string& s2){
            return s1.size()<s2.size();
        }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<words.size();i++){
        cout<<words[i]<<"\n";
        }
        int maxi=1;
        for(int i=0;i<words.size();i++){
            int count=0;
            for(int j=0;j<i;j++){
                if(compareStr(words[j],words[i]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    count=1+dp[j];
                }
            }
            if(count>maxi) maxi=count;
        }
        return maxi;
    }
};