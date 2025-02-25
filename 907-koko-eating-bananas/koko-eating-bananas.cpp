class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int last=INT_MIN,first=1,mid=0,ans=INT_MAX;
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            last=max(last,piles[i]);
            sum+=piles[i];
        }
        long long calci;
        while(first<=last){
            calci=0;
            mid=(first+last)/2;
            for(int i=0;i<piles.size();i++){
                calci+=ceil((double)piles[i]/(double)mid);
            }
            if(calci<=h){
                ans=min(ans,mid);
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
    return ans;}
};