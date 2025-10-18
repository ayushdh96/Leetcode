class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        map<int,pair<char,int>> sCount;
        char prev=s[0];
        int characterCounter=1;
        int currentPosition=0;
        for(int i=1;i<s.size();i++){
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
            if((it[it.size()-1] != s[s.size()-1]) || s.size()<it.size() )continue;
            bool flag=true;
            for(int i=0;i<it.size()-1;i++){
                if(sCount[currentPosition].first!=it[i]){
                    flag=false;
                    break;
                }
                else if(sCount[currentPosition].first!=it[i+1]){
                    if(sCount[currentPosition].second<3 && characterCounter!=sCount[currentPosition].second){
                        flag=false;
                        break;
                    }
                    if(characterCounter>sCount[currentPosition].second){ flag=false; break; }
                    currentPosition++;
                    characterCounter=0;
                }
                characterCounter++;
            }
            if(sCount[currentPosition].first!=it[it.size()-1] || sCount[currentPosition].second<3 && characterCounter!=sCount[currentPosition].second
            || currentPosition<sCount.size()-1){
                flag=false;
            }
            if(flag==true){
                ans++;
            }
            flag=true;
            characterCounter=1;
            currentPosition=0;

        }
    return ans;
    }
};