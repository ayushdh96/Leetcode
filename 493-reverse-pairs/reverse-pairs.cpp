class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count=0;
        int l=0;
        int r=nums.size()-1;
        mergeSort(nums,l,r,count);
        return count;
    }

    void counter(vector<int>& nums, int l, int r, int mid,int &count){
        int left=l;
        int right=mid+1;
        while(left<=mid && right<=r){
            if((long long)nums[left]>(long long)nums[right]*2){
                count=count+(mid-left+1);
                right++;
            }
            else{
                left++;
                }
            }
        }
    void mergeSort(vector<int>& nums, int l, int r, int &count){
        if(l>=r){return;}
        int mid=(l+r)/2;
        mergeSort(nums,l,mid,count);
        mergeSort(nums,mid+1,r,count);
        counter(nums,l,r,mid,count);
        merge(nums, l,r,mid,count);
    }

    void merge(vector<int>& nums,int l,int r,int mid,int &count){
        vector<int> temp;
        int left=l, right=mid+1;
        while(left<=mid && right<=r){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        if(left<=mid){
            for(int i=left;i<=mid;i++){
                temp.push_back(nums[i]);
            }
        }
        else if(right<=r){
            for(int i=right;i<=r;i++){
                temp.push_back(nums[i]);
            }
        }

        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }

        }
};