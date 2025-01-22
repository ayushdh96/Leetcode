class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int starting_index=0,last_index=0,sum=0,max=nums[starting_index],flag=0;
        while(last_index<nums.size()){
            if(nums[starting_index]<=0){
                if(nums[starting_index]>max){
                    max=nums[starting_index];
                }
            }
            if(nums[starting_index]<=0 && flag==0){
                starting_index++;
                last_index=starting_index;
            }
            else if(nums[starting_index]>0){
                flag=1;
                sum=sum+nums[last_index];
                if(sum>max){
                    max=sum;
                }
                else if(sum<0){
                    flag=0;
                    sum=0;
                }
                last_index++;
            }
        }
        return max;
    }
};