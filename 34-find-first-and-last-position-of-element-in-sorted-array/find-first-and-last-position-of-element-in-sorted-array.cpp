class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower=-1,upper=nums.size(),first=0,last=nums.size()-1,mid=0;
        while(first<=last){
            mid=(first+last)/2;
            if(nums[mid]>=target){
                lower=mid;
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        first=0,last=nums.size()-1,mid=0;
        while(first<=last){
            mid=(first+last)/2;
            if(nums[mid]>target){
                upper=mid;
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        if(nums.size()==0){
            return {-1,-1};
        }
        else if(lower == -1 || nums[lower]!=target){
            return {-1,-1};
        }
        else{
            if(nums[upper-1]!=target){
                return {lower,lower};
            }
            else{
            return{lower,upper-1};}
        }

    }
};