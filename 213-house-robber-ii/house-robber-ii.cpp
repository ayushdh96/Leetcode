class Solution {
private:
    int houseRobbers(int idx ,vector<int>& dp, vector<int>& nums){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick= nums[idx] + houseRobbers(idx-2,dp,nums);
        int noPick=houseRobbers(idx-1,dp,nums);
        return dp[idx]=max(pick,noPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        vector<int> temp1,temp2;
        int len=nums.size();
        if(len==1) return nums[0];
        for(int i=0;i<len;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=len-1) temp2.push_back(nums[i]);
        }
        return max(houseRobbers(temp2.size()-1,dp1,temp2) , houseRobbers(temp1.size()-1,dp2,temp1));
    }
};