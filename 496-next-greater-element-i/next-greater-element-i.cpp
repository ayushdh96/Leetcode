class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                int curr=st.top();
                while(curr<=nums2[i]){
                    st.pop();
                    if(!st.empty())curr=st.top();
                    else break;
                }
                if(st.empty()) mpp[nums2[i]]=-1;
                else mpp[nums2[i]]=curr;
                st.push(nums2[i]);
            }
        }
        vector<int> ans2;
        for(int i=0;i<nums1.size();i++){
            ans2.push_back(mpp[nums1[i]]);
        }
        return ans2;
    }
};