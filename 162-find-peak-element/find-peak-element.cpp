class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size(),first=1,last=nums.size()-2,mid=0;
        if(size==1){return 0;}
        else if(nums[first-1]>nums[first]){return first-1;}
        else if(nums[last+1]>nums[last]){return last+1;}
        else{
            while(first<=last){
                mid=(first+last)/2;
                if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid+1]){
                    first=mid+1;
                }
                else if(nums[mid]>nums[mid+1]){
                    last=mid-1;
                }
                else{
                    last=mid-1;
                }
            }
        }
        return -1;
    }
};