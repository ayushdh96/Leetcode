class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=nums[0] , count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==element){
                count++;
            }
            else if(nums[i]!=element){
                count--;
            }
            if(count==0){
                element=nums[i+1];
            }

        }
        return element;
    }
};