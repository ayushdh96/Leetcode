class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size(),vector<string>());
        int pointer1=0;
        bool shouldIterate=true;
        string temp="";
        sort(products.begin(),products.end());
        for(int i=0;i<searchWord.size();i++){
            int insertions=0;
            bool wasPointerMoved=false;
            temp+=searchWord[i];
            int tempHolding=0;
            for(int j=pointer1;j<products.size();j++){
                if(temp==products[j].substr(0,i+1)){
                    insertions++;
                    ans[i].push_back(products[j]);
                    if(!wasPointerMoved){
                        wasPointerMoved=true;
                        tempHolding=j;
                }
                if(insertions==3){
                    break;
                }
                }
                else if(temp<products[j].substr(0,i+1)){
                    break;
                }
            }
            if(insertions==0){
                return ans;
            }
            if(wasPointerMoved){
            pointer1=tempHolding;}
        }
    return ans;}
};