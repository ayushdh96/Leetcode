class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int> ans;
        vector<int> list(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(list[i]==1){
                for(int j=i*i;j<=n;j=j+i){
                    list[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(list[i]) ans.push_back(i);
        }
        return ans;
    }
};