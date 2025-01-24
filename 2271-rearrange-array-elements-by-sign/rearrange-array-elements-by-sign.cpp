class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> newArr(nums.size());
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++){
            if((pos<=nums.size()-1) && nums[i]>0){
                newArr[pos]=nums[i];
                pos+=2;
            }
            if((neg<=nums.size()-1) && nums[i]<0){
                newArr[neg]=nums[i];
                neg+=2;
            }
        }
        return newArr;
    }
};