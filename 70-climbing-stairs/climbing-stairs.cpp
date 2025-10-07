class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=prev2+prev;
            prev2=prev;
            prev=ans;
        }
        if(n==0) return 0;
        else if(n==1) return 1;
        else return ans;
    }
};