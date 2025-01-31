class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<k){
            k=k%nums.size();
        }  
        int left=0,right=nums.size()-1-k;
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        left=nums.size()-k;
        right=nums.size()-1;
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        reverse(nums.begin(),nums.end());}
    
};