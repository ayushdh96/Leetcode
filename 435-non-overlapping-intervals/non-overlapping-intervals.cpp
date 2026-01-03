class Solution {
public:
    static bool comp(vector<int>& first, vector<int>& second){
        return second[1]>first[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=0,r=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(r>intervals[i][0]) count++;
            else r=intervals[i][1];
        }
        return count;
    }
};