class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i=0;i<paragraph.length();i++){
            if((paragraph[i]>='a'&& paragraph[i]<='z')|| paragraph[i]>='A'&& paragraph[i]<='Z'){
                paragraph[i]=tolower(paragraph[i]);
            }
            else{
                paragraph[i]=' ';
            }
        }
        stringstream ss(paragraph);
        string word;
        unordered_map<string, int> mpp;
        int max_counter=0;
        string max_word;
        for(int i=0;i<banned.size();i++){
            mpp[banned[i]]=-1;
        }
        while(ss>>word){
            if(mpp.find(word)!=mpp.end()){
                if(mpp[word]==-1){
                    continue;
                }
                else{
                    mpp[word]+=1;
                    if(mpp[word]>max_counter){
                        max_counter=mpp[word];
                        max_word=word;
                    }
                }
            }
            else{
                mpp[word]+=1;
                if(mpp[word]>max_counter){
                        max_counter=mpp[word];
                        max_word=word;
                    }
            }
        }
        return max_word;
    }
};