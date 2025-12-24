class Solution {
public:
    int calculateSum(vector<int>& nums, int goal){
        int l=0,r=0,sum=0,count=0;
        while(r<nums.size()){
            sum=sum+(nums[r]%2);
            while(sum>goal){
                sum=sum-(nums[l]%2);
                l++;
            }
            count=count+r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        if(k!=0) count=calculateSum(nums,k) - calculateSum(nums,k-1);
        else count=calculateSum(nums,k);
        return count;
    }
};