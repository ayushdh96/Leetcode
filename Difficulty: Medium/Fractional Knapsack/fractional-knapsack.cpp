class Solution {
  public:
    static bool comp(pair<double,double>& a, pair<double,double>& b){
        double first=a.first/a.second;
        double second=b.first/b.second;
        return first>second;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,double>> newArr;
        for(int i=0;i<val.size();i++){
            newArr.push_back({val[i],wt[i]});
        }
        sort(newArr.begin(),newArr.end(),comp);
        int i=0;
        double ans=0.0;
        while(i<newArr.size()){
            if(capacity>=newArr[i].second){
                ans=ans+newArr[i].first;
                capacity=capacity-newArr[i].second;
            }
            else{
                ans=ans+((newArr[i].first/newArr[i].second)*capacity);
                capacity=0;
            }
            if(capacity==0) return ans;
            i++;
        }
        return ans;
    }
};
