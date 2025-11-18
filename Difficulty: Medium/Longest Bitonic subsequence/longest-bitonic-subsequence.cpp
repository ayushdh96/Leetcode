class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int maxi1=0;
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp1[j]>dp1[i]){
                    dp1[i]=1+dp1[j];
                    count=1+dp1[j];
                }
            }
            if(maxi1<count) maxi1=count;
        }
        vector<int> dp2(n,1);
        int maxi2=0;
        for(int i=n-1;i>=0;i--){
            int count=0;
            for(int j=n-1;j>=i+1;j--){
                if(nums[i]>nums[j] && 1+dp2[j]>dp2[i]){
                    dp2[i]=1+dp2[j];
                    count=1+dp2[j];
                }
            }
            if(maxi2<count) maxi2=count;
        }
        if(maxi1==n||maxi2==n) return false;
        int maxi=0;
for(int i=0;i<n;i++){
    if(dp1[i] > 1 && dp2[i] > 1) {        // <-- key fix
        int count = dp1[i] + dp2[i] - 1;
        if(maxi < count) maxi = count;
    }
}
return maxi;
        
    }
};
