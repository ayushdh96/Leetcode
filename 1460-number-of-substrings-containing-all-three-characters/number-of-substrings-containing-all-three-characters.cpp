class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen={-1,-1,-1};
        int pointer=0,count=0;
        while(pointer<s.size()){
            lastSeen[s[pointer]-'a']=pointer;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
                count=count+ min(lastSeen[0],min(lastSeen[1],lastSeen[2]))+1;
            }
            pointer++;
        }
        return count;
    }
};