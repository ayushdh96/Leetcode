class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        vector<int> variables;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
        }
        for(auto &it:mpp){
            if(it.second>nums.size()/3){
                variables.push_back(it.first);
            }
        }
        return variables;
    }
};