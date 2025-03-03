class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int first=INT_MAX, last=INT_MIN;
        for(int i=0;i<nums.size();i++){
            first=min(first,nums[i]);
            last=max(nums[i],last);
        }
        int mid=0,counter,ans=INT_MAX;
        first=1;
        while(first<=last){
            counter=0;
            mid=(first+last)/2;
            for(int i=0;i<nums.size();i++){
                //cout<<nums[i]<<" "<<mid<<" "<<ceil( double(nums[i])/mid)<<endl;
                counter=counter+ceil(double(nums[i])/mid);
            }
            if(counter<=threshold){
                ans=min(mid,ans);
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        return ans;
    }
};