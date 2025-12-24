class Solution {
public:
    int countSubArray(vector<int>& nums, int k){
        map<int,int> mpp;
        int l=0,r=0,count=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count=count+r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count=0;
        count=countSubArray(nums,k)-countSubArray(nums,k-1);
        return count;

    }
};