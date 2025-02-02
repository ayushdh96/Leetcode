class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int j,k;
        sort(nums.begin(),nums.end()); // nlog n
        int sum=0;
        for(int i=0;i<nums.size();i++){
            j=i+1;
            k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){continue;}
            while(j<k){
            sum=nums[i]+nums[j]+nums[k];
            //cout<<nums[i]<<"   "<<nums[j]<<". "<<nums[k]<<"  "<<sum<<endl;
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while((nums[j]==nums[j-1]) && j<k){j++;}
                while((nums[k]==nums[k+1]) && j<k){k--;}
            }
            }
        }
        return ans;
    }
};