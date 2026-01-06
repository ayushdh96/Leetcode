class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]==']' || s[i]=='}' || s[i]==')'){
                if(st.size()==0) return false;
                char ch=st.top();
                if((s[i]==']' && ch!='[') || (s[i]==')' && ch!='(') || (s[i]=='}' && ch!='{'))
                return false;
                else st.pop();
            }
            else st.push(s[i]);
            i++;
        }
        if(st.size()>0) return false;
        return true;
    }
};