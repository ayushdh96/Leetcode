class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sset;
        int longest=1;
        for(int i =0;i<nums.size();i++){
            sset.insert(nums[i]);
        }
        for(auto& it:sset){
            if(sset.find(it-1) == sset.end()){
                int value=it;
                int count=1;
                while(sset.find(value+1)!= sset.end()){
                    count++;
                    value++;
                }
                longest=max(longest,count);
            }
        }
        if(nums.size()==0){longest=0;}
        return longest;
    }
};