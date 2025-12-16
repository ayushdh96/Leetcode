class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxi=0;
        int kCount=0;
        int count=0;
        while(r<nums.size()){
            if(kCount<k || nums[r]==1){
                if(nums[r]==0) kCount++;
                count=r-l+1;
                maxi=max(count,maxi);
                r++;
            }
            else {
                while(kCount>=k){
                    if(nums[l]==0) kCount--;
                    l++;
                }
                count=r-l+1;
                maxi=max(count,maxi);
            }
            
        }
        return maxi;
    }
};