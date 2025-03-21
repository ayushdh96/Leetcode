class Solution {
public:
    static bool compMethod( pair<string,int>& a,  pair<string,int>& b)
        {
            if(a.second!=b.second){
                return a.second>b.second;
            }
            else return a.first< b.first;
        }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp1;
        vector<string> ans;
        vector<pair<string,int>> copy;
        for(int i=0;i<words.size();i++){
            mp1[words[i]]+=1;
        }

        for(auto it:mp1){
            copy.push_back(it);
        }

        sort(copy.begin(),copy.end(),compMethod);

        for(int i=0;i<k;i++){
            ans.push_back(copy[i].first);
        }

        return ans;
    }
};