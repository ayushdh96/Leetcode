class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,last=nums.size()-1;
        int value=recur(nums,l,last,target);
        return value;
    }

    int recur(vector<int>& nums,int l, int last ,int target){
        int mid=(l+last)/2;
        if(l>last){return -1;}
        else if(nums[mid]==target){ return mid;}
        else if(nums[mid]>target){return recur(nums,l,mid-1,target);}
        else {return recur(nums,mid+1,last,target);}
}
};