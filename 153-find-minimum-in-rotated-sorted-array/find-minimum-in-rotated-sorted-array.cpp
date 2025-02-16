class Solution {
public:
    int findMin(vector<int>& nums) {
       int first=0,last=nums.size()-1,mid=0,smallest=INT_MAX;
        while(first<=last){
            mid=(first+last)/2;
            if(nums[mid]>=nums[first]){
                smallest=min(nums[first],smallest);
                first=mid+1;
            }
            else{
                smallest=min(nums[mid],smallest);
                last=mid-1;
            }
        } 
    return smallest;
    }

};