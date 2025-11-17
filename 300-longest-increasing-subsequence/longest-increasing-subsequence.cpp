class Solution {
private:
    int recur(int index, int prev, vector<int>& nums, vector<vector<int>>& dp){
        //base case
        if(index==nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int length=recur(index+1,prev,nums,dp);
        if(prev==-1 || nums[index]>nums[prev]){
            return dp[index][prev+1]=max(length, 1+recur(index+1,index,nums,dp));
        }
        return dp[index][prev+1]=length;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        //return recur(0,-1,nums,dp);
        /**vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int length=dp[index+1][prev+1];
                if(prev==-1 || nums[index]>nums[prev]){
                    dp[index][prev+1]=max(length, 1+dp[index+1][index+1]);
                }
                else dp[index][prev+1]=length;
            }
        }
        return dp[0][0];**/
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            else{
                int index=lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[index]=nums[i];
            }
        }
        return temp.size();
    }
};