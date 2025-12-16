class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int length=s.size();
        int l=0,r=0;
        int maxi=0;
        int count=0;
        while(r<length){
            if(mpp.find(s[r])==mpp.end()){
                mpp[s[r]]=r;
                count++;
                r++;
            }
            else{
                int leftValue=mpp[s[r]];
                if(leftValue >= l) l = leftValue + 1;
                mpp[s[r]]=r;
                count=r-l+1;
                r++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};