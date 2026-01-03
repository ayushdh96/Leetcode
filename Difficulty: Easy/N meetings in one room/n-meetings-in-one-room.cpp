class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> meet;
        for(int i=0;i<start.size();i++){
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        int time=-1,ans=0;
        for(int i=0;i<meet.size();i++){
            if(meet[i].second>time){
                time=meet[i].first;
                ans++;
            }
        }
        return ans;
    }
};