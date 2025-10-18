class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minq;
        deque<int> maxq;
        int maxLength=0;
        int fp=0,sp=0;
        int length=nums.size();
        while(sp<nums.size()){
            int currVal=nums[sp];
            while(!minq.empty() && currVal<nums[minq.back()]) minq.pop_back();
            minq.push_back(sp);
            while(!maxq.empty() && currVal>nums[maxq.back()]) maxq.pop_back();
            maxq.push_back(sp);

            int currMax=nums[maxq.front()];
            int currMin=nums[minq.front()];
            if(currMax-currMin > limit){
                while(fp<=sp && currMax-currMin > limit){
                    fp++;
                    if(maxq.front()<fp) maxq.pop_front();
                    if(minq.front()<fp) minq.pop_front();
                    currMax=nums[maxq.front()];
                    currMin=nums[minq.front()];
                }
            }
            if(currMax-currMin <= limit){
                maxLength=max(sp-fp+1,maxLength);
                sp++;
            }
        }
        return maxLength;
    }
};