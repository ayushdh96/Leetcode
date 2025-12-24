class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        map<char,int> mpp;
        int minLength=1e9;
        int startIndex=-1;
        int count=0;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        while(r<s.size()){
            mpp[s[r]]--;
            if(mpp[s[r]]>=0) count++;
            while(count==t.size()){
                if(minLength>r-l+1){
                    minLength=r-l+1;
                    startIndex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minLength);
    }
};