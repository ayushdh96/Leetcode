// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        int i=0,j=arr.size()-1;
        sort(arr.begin(),arr.end());
        set<pair<int,int>> st;
        while(i<j){
            if(arr[i]+arr[j]==0) {st.insert({arr[i],arr[j]}); i++;j--;}
            else if(arr[i]+arr[j]>0) j--;
            else i++;
        }
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};