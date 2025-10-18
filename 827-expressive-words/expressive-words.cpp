class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        map<int,pair<char,int>> sCount;
        char prev=s[0];
        int characterCounter=1;
        int currentPosition=0;

        for(int i=1;i<(int)s.size();i++){
            if(prev!=s[i]){
                sCount[currentPosition]={prev,characterCounter};
                characterCounter=0;
                prev=s[i];
                currentPosition++;
            }
            characterCounter++;
        }
        sCount[currentPosition]={prev,characterCounter};

        currentPosition=0;
        characterCounter=1;

        for(auto it:words){
            if((it.back() != s.back()) || s.size()<it.size()) continue;

            bool flag=true;
            currentPosition=0;
            characterCounter=1;

            for(int i=0;i<(int)it.size()-1;i++){
                // guard + char must match current S group
                if(sCount.count(currentPosition)==0 || sCount[currentPosition].first!=it[i]){
                    flag=false; break;
                }
                // boundary in the WORD, not vs S char
                if(it[i]!=it[i+1]){
                    // check stretchy rule against current S group
                    int sc = sCount[currentPosition].second;
                    if(sc<3){
                        if(characterCounter!=sc){ flag=false; break; }
                    }else{
                        if(characterCounter>sc){ flag=false; break; }
                    }
                    currentPosition++;
                    characterCounter=0;
                }
                characterCounter++;
            }

            // final group checks
            if(flag){
                if(sCount.count(currentPosition)==0 || sCount[currentPosition].first!=it.back()){
                    flag=false;
                }else{
                    int sc = sCount[currentPosition].second;
                    if(sc<3){
                        if(characterCounter!=sc) flag=false;
                    }else{
                        if(characterCounter>sc) flag=false;
                    }
                }
            }
            // must consume all groups in S
            if(flag && currentPosition != (int)sCount.size()-1) flag=false;

            if(flag) ans++;
        }
        return ans;
    }
};