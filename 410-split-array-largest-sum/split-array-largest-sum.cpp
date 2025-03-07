int findPages(vector<int>& arr, int m) {
    int sum=0,max_count=INT_MIN,mid=0,students=1,pages_counter=0;
    if(arr.size()<m){return -1;}
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        max_count=max(max_count,arr[i]);
    }
    while(max_count<=sum){
        mid=(max_count+sum)/2;
        pages_counter=0;
        students=1;
        for(int i=0;i<arr.size();i++){
            if(pages_counter+arr[i]<=mid){
                pages_counter+=arr[i];
            }
            else{
                students++;
                pages_counter=arr[i];
            }
        }
        if(students<=m){
            sum=mid-1;
            
        }
        else{
            max_count=mid+1;
        }
    }
    return max_count;
}
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};