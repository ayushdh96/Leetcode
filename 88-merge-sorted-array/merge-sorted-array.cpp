class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        if(j<n){
            for(int k=j;k<n;k++){
                arr.push_back(nums2[k]);
            }
        }
        else if(i<m){
            for(int k=i;k<m;k++){
                cout<<" "<<nums1[k];
                arr.push_back(nums1[k]);
            }
        }
        for(int k=0;k<m+n;k++){
            nums1[k]=arr[k];
        }
    }
};