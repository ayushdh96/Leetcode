class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        vector<int> variables;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]==((nums.size()/3)+1)){
                variables.push_back(nums[i]);
                
            }
        }
        return variables;
    }
};