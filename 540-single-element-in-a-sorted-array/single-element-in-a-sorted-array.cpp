class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int first=1, last=nums.size()-2,mid=0;
        if(nums.size()==1){return nums[0];}
        else if(nums[last]!=nums[last+1]){return nums[last+1];}
        else if(nums[first]!=nums[first-1]){return nums[first-1];}
        else{
            while(first<=last){
            mid=(first+last)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid]==nums[mid+1])|| (mid%2==1) && nums[mid-1]==nums[mid]){
                first=mid+1;
            }
            else if((mid%2==0 && nums[mid]==nums[mid-1])|| (mid%2==1) && nums[mid+1]==nums[mid]){
                last=mid-1;
            }
            }  
        }
    return -1;
    }
};