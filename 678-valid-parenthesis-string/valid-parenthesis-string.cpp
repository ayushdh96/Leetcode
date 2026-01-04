class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                if(min!=0) min--;
                max--;
                if(max<0) return false;
            }
            else{
                if(min!=0) min--;
                max++;
            }
            i++;
        }
        if(min==0) return true;
        return false;
    }
};