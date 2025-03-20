class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mpp;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        int parition=0,last_index=0,current_index=0;
        for(int i=0;i<s.size();i++){
            current_index=i;
            parition++;
            if(mpp[s[i]]>last_index){
                last_index=mpp[s[i]];
            }
            if(current_index==last_index){
                cout<<current_index;
                ans.push_back(parition);
                parition=0;
                last_index=current_index;
            }
        }
        return ans;
    }
};