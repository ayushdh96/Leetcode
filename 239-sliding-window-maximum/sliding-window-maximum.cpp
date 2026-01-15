class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>> dq;
        int count=1;
        for(int i=0;i<=nums.size()-k;i++){
            if(count<k){
                while(count<=k){
                while(!dq.empty() && dq.back().first<=nums[count-1]){
                    dq.pop_back();
                }
                dq.push_back({nums[count-1],count-1});
                count++;
                }
                ans.push_back(dq.front().first);
            }
            else{
                if(!dq.empty() && dq.front().second<i) dq.pop_front();
                while(!dq.empty() && dq.back().first<=nums[count-1]){
                    dq.pop_back();
                }
                dq.push_back({nums[count-1],count-1});
                ans.push_back(dq.front().first);
                count++;

            }
        }
        return ans;
    }
};