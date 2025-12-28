// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        if(bt.size()<=1) return 0;
        sort(bt.begin(),bt.end());
        long long sum=0,waitTime=0;
        for(int i=0;i<bt.size()-1;i++){
            sum=sum+bt[i];
            waitTime=waitTime+sum;
        }
        return waitTime/bt.size();
    }
};