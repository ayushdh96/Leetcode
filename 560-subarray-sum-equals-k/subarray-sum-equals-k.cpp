class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        int counter=0;
        mpp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.find(sum-k)==mpp.end()){
                mpp[sum]+=1;
            }
            else{
                counter+=mpp[sum-k];
                mpp[sum]+=1;
            }
        }
        return counter;
    }
};