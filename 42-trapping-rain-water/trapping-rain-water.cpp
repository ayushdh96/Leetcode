class Solution {
public:
    int trap(vector<int>& height) {
        int low=0,total=0,high=height.size()-1;
        int lmax=0,rmax=0;
        while(low<high){
            if(height[low]<=height[high]){
                if(lmax>height[low]){
                    total+=lmax-height[low];
                }
                else{
                    lmax=height[low];
                }
                low++;
            }
            else{
                if(rmax>height[high]){
                    total=total+rmax-height[high];
                }
                else{
                    rmax=height[high];
                }
                high--;
            }
        }
    return total;
    }
};