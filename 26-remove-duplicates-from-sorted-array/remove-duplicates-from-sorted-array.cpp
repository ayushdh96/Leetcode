class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[pointer]=nums[i+1];
                pointer++;
            }
        }
        return pointer;
    }
};