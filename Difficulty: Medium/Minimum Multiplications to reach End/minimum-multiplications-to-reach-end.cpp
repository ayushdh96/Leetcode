// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>distance(100000,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,start});
        distance[start]=0;
        if(start==end) return 0;
        while(!q.empty()){
            int currNode=q.front().second;
            int currDistance=q.front().first;
            q.pop();
            
            int newDistance=currDistance+1;
            for(int i=0;i<arr.size();i++){
                int currMultiplication=(currNode*arr[i])%100000;
                if(currMultiplication==end) return newDistance;
                if(newDistance<distance[currMultiplication]){
                    distance[currMultiplication]=newDistance;
                    q.push({newDistance,currMultiplication});
                }
            }
        }
        return -1;
    }
};
