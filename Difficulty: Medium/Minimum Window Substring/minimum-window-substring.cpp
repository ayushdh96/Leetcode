class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int first,second=0;
        int min_length=INT_MAX;
        string ans="";
        while(first<s1.size()){
            if(s1[first]!=s2[0]){
                first++;
            }
            else{
                second=first;
                string substring="";
                int secondString=0;
                while(second<s1.size() && secondString<s2.size()){
                    substring=substring+s1[second];
                    if(s1[second]==s2[secondString]){
                        secondString++;
                    }
                    second++;
                }
                if(min_length>substring.size() && secondString==s2.size()){
                    min_length=substring.size();
                    ans=substring;
                }
            first++;
                
            }
        }
        return ans;
    }
};
