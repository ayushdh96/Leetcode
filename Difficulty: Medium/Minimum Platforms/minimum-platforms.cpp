class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int a=0,d=0;
        int maxcount=0,count=0;
        while(a<arr.size()){
            if(arr[a]<=dep[d]){
                a++;
                count++;
            }
            else{
                d++;
                count--;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};
