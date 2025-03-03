class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int first=0,last=arr.size()-1,mid=0;
        if(arr[last]==arr.size()){
            return arr[last]+k;
        }
        while(first<=last){
            mid=(first+last)/2;
            if((arr[mid]-(mid+1))<k){
                first=mid+1;
            }
            else{
                last=mid-1;
            }
            
        }
        cout<< last;
        return ( last +1 +k);
    }
};