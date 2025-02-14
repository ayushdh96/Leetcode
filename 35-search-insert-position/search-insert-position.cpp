class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0, ans = nums.size();
        while (left <= right) {
            mid = (left + right) / 2;
            if ( nums[mid]>=target) {
                right = mid - 1;
                 ans=mid;
            } else {
                
                left = left + 1;
            }
        }
        return ans;
    }
};