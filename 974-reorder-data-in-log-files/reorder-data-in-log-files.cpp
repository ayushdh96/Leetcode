class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>> digits;
        vector<pair<string,string>> characters;
        vector<string> ans;
        for(auto it : logs){
            string f="";
            string s="";
            bool flag=false;
            for(int i=0;i<(int)it.size();i++){
                if(it[i]==' ' && flag==false){
                    flag=true;
                    continue;
                }
                if(flag==true){
                    s+=it[i];
                }
                else{
                    f+=it[i];
                }
            }
            if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
                characters.push_back({s,f});
            }
            else{
                digits.push_back({s,f});
            }
        }
            sort(characters.begin(),characters.end());
            for(auto it:characters){
                ans.push_back(it.second+" "+it.first);
            }
            for(auto it:digits){
                ans.push_back(it.second+" "+it.first);
            }
          return ans;  
        }
    
};