class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size()<=k){
            return points;
        }
        vector<vector<int>>ans;
        priority_queue<pair<double,pair<int,int>>,vector<pair<double, pair<int,int>>>,greater<pair<double,pair<int,int>>>> q;
        for(int i=0;i<points.size();i++){
            q.push({sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])),{points[i][0],points[i][1]}});
        }
        for(int i = 0; i < k; i++){
    int x=q.top().second.first;
    int y=q.top().second.second;
    ans.push_back({x,y});
    q.pop();
}
        return ans;
    }
};