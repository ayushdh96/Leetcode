class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size()<=k){
            return points;
        }
        vector<vector<int>>ans;
        /**vector<double> distance;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            distance.push_back(sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])));
        }
        vector<double> distanceCopy=distance;
        sort(distanceCopy.begin(),distanceCopy.end());
        double cutOff=distanceCopy[k-1];
        for(int i=0;i<distance.size();i++){
            if(distance[i]<=cutOff){
                ans.push_back(points[i]);
            }
        }**/
        priority_queue<pair<double,pair<int,int>>,vector<pair<double, pair<int,int>>>,greater<pair<double,pair<int,int>>>> q;
        for(int i=0;i<points.size();i++){
            q.push({sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])),{points[i][0],points[i][1]}});
        }
        for(int i = 0; i < k; i++){
    auto [x, y] = q.top().second;
    ans.push_back({x, y});
    q.pop();
}
        return ans;
    }
};