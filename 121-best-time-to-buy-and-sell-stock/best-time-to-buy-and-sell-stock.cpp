class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int point1=0,point2=0,max=0;
        while(point2<prices.size()){
            if(prices[point2]-prices[point1]>=0){
                if(max<prices[point2]-prices[point1]){
                    max=prices[point2]-prices[point1];
                }
                point2++;
            }
            else{
                point1++;
                if(point2<point1){
                    point2=point1;
                }
            }
        }
        return max;
    }
};