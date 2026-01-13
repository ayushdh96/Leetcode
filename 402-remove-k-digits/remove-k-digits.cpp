class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for(int i=0;i<num.size();i++){
            if(st.size()==0) st.push_back(num[i]);
            else{
                if(int(num[i])>=int(st.back())) st.push_back(num[i]);
                else{
                    while(k>0 && st.size()>0 && num[i]<st.back()){
                        k--;
                        st.pop_back();
                    }
                    st.push_back(num[i]);
                }
            }
        }
        while(k!=0){
            k--;
            st.pop_back();
        }
        string ans;
        int flag=0;
        int i = 0;
        while (i < (int)st.size() && st[i] == '0') i++;
        for(int j=i;j<st.size();j++){
            ans.push_back(st[j]);
        }
        return ans.size()==0?"0":ans;;
    }
};