class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mid=0,counter=0,no_of_boq=0;
        if(bloomDay.size()<(long long)m*k){
            return -1;
        }
        int first=INT_MAX,last=INT_MIN,ans=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            first=min(first,bloomDay[i]);
            last=max(last,bloomDay[i]);
        }

        while(first<=last){
            mid=(first+last)/2;
            no_of_boq=0,counter=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    counter++;
                }
                else{
                    no_of_boq=no_of_boq+(counter/k);
                    counter=0;
                }
                
            }
            if(counter>0){
                    no_of_boq=no_of_boq+(counter/k); 
                }
            if(no_of_boq>=m){
                ans=min(ans,mid);
                 last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        return ans;
    }
};