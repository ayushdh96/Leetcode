class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),1);
        sort(nums.begin(),nums.end());
        int maxi=0;
        int max_index=0;
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            int count=0;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    
                    dp[i]=dp[j]+1;
                    count=dp[j]+1;
                    hash[i]=j;
                    
                }
            }
            if(count>maxi){
                maxi=count;
                max_index=i;
            }
        }
        vector<int> temp;
        while(hash[max_index]!=max_index){
            temp.push_back(nums[max_index]);
            max_index=hash[max_index];
        }
        temp.push_back(nums[max_index]);
        return temp;
    }
};