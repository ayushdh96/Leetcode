class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>vec;
        int start=0;
        int end=0;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[start][0] && intervals[i][0]<=intervals[end][1]){
          if(intervals[end][1]<intervals[i][1]){
            end=i;
          }     
            }
            else{
                vec.push_back({intervals[start][0],intervals[end][1]});
                start=i;
                end=i;
            }
        }
            vec.push_back({intervals[start][0],intervals[end][1]});
        return vec;
    }
};