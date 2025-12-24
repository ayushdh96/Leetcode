class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int longestSeq=0;
        int maxFreq=0;
        int l=0,r=0;
        while(r<s.size()){
            count[s[r]-'A']=count[s[r]-'A']+1;
            maxFreq=max(maxFreq,count[s[r]-'A']);
            while(k<r-l+1-maxFreq){
                count[s[l]-'A']=count[s[l]-'A']-1;
                l++;
                maxFreq=0;
                for(int i=0;i<26;i++){
                    maxFreq=max(maxFreq,count[i]);
                }
            }
            longestSeq=max(longestSeq,r-l+1);
            r++;
        }
        return longestSeq;
    }
};