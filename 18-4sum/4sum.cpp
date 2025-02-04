class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l,k;
        long long sum;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]){continue;}
                k=j+1;
                l=nums.size()-1;
                while(k<l){
                    sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(nums[k]==nums[k-1] && k<l){k++;}
                        while(nums[l]==nums[l+1] && k<l){l--;}
                    }
                }
            }

        }
        return ans;
    }
};