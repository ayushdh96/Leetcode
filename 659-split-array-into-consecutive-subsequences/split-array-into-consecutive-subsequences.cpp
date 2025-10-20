class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mpp1;
        map<int,int>mpp2;
        for(int i=0;i<nums.size();i++){
            mpp1[nums[i]]=mpp1[nums[i]]+1;
        }
        
        for(auto it: nums){
            if(mpp1[it]==0){
                continue;
            }
            mpp1[it]--;
            if(mpp2[it-1]>0){
                mpp2[it-1]--;
                mpp2[it]++;
            }
            else if(mpp1[it+1]!=0 && mpp1[it+2]!=0 ){
                mpp1[it+1]--;
                mpp1[it+2]--;
                mpp2[it+2]++;
            }
            
            else return false;
        }
        return true;
    }
};