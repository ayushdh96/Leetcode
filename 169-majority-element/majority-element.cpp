class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()){
                hash[nums[i]]+=1;
            }
            else {
                hash[nums[i]]=1;
            }
        }
        int element,max=0;
        for(auto& i:hash){
            if(i.second>max)
            {
                max=i.second;
                element=i.first;
            }
        }
        return element;
    }
};