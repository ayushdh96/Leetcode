class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mpp;
        int l=0,r=0,maxi=0,count=0;
        while(r<fruits.size()){
                mpp[fruits[r]]++;
                if(mpp.size()<=2){
                    maxi=max(maxi,r-l+1);
                    r++;
                }
                else{
                    while(mpp.size()>2){
                        mpp[fruits[l]]--;
                        if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                        l++;
                    }
                    maxi=max(maxi,r-l+1);
                    r++;
                }

            
        }
        return maxi;
    }
};