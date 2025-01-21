class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>hash;
        int rem=0;
        for(int i =0; i<nums.size();i++){
            rem=target-nums[i];
            if(hash.find(rem)!=hash.end()){
                return {hash[rem],i};
            }
            hash[nums[i]]=i;
        }
        
        return {0,0};
    }
};