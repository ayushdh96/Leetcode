class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> wl;
        for(int i=0;i<wordList.size();i++){
            wl.insert(wordList[i]);
        }
        if(wl.find(endWord)==wl.end()) return 0;
        q.push({beginWord,1});
        int sequence=0;
        while(!q.empty()){
            string curr=q.front().first;
            int currSeq=q.front().second;
            q.pop();
            for(int i=0;i<curr.length();i++){
                string temp=curr;
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(temp==endWord){
                        wl.erase(temp);
                        return currSeq+1;
                        
                    }
                    if(wl.find(temp)!=wl.end()) {
                        wl.erase(temp);
                        q.push({temp,currSeq+1});
                    }
                }
            }
        }
        return sequence;
    }
};