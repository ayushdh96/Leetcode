class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int last=0,first=INT_MIN,ans=INT_MAX,counter=0,day_counter=0;
        for(int i=0;i<weights.size();i++){
            last+=weights[i];
            first=max(first,weights[i]);
        }
        int mid=0;
        while(first<=last){
            mid=(first+last)/2;
            counter=0;
            day_counter=0;
            for(int i=0;i<weights.size();i++){
                if(counter+weights[i]>mid){
                    day_counter++;
                    counter=0;
                }
                counter+=weights[i];
                
            }
            day_counter++;
            if(day_counter<=days){
                ans=mid;
                last=mid-1;
            }
            else {
                first=mid+1;
            }
            
        }
        return ans;
    }
};