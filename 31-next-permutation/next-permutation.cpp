class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakPoint=i-1;
                break;
            }
        }
        if(breakPoint==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[breakPoint]){
                    swap(nums[i],nums[breakPoint]);
                    break;
                }
            }
            reverse(nums.begin()+ breakPoint + 1,nums.end());
        }
    }
};