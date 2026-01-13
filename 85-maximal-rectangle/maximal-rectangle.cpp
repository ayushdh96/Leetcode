class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        stack<int> value;
        int maxval=-1e9;
        if(!heights.empty()){
            index.push(0);
            value.push(heights[0]);
        }
        for(int i=1;i<heights.size();i++){
            if(!value.empty() && value.top()<heights[i]){
                index.push(i);
                value.push(heights[i]);
            }
            else{
                while(!value.empty()){
                    int currvalue=value.top();
                    int currindex=index.top();
                    value.pop();
                    index.pop();
                    int psv=index.empty()?-1:index.top();
                    int area=(i-psv-1)*currvalue;
                    maxval=max(maxval,area);
                    if(value.empty() || (!value.empty() && value.top()<heights[i])){
                        value.push(heights[i]);
                        index.push(i);
                        break;
                    }
                }
            }
            
        }
        int nse=index.empty()?-1:index.top()+1;
        while(!value.empty()){
            int currvalue=value.top();
            index.pop();
            value.pop();
            int psv=index.empty()?-1:index.top();
            int area=(nse-psv-1)*currvalue;
            maxval=max(maxval,area);
        }
        return maxval;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> prefixSum(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int j=0;j<matrix[0].size();j++){
            int sum=0;
            for(int i=0;i<matrix.size();i++){
                int currValue=matrix[i][j]=='1'?1:0;
                sum=currValue==1?sum+currValue:0;
                prefixSum[i][j]=sum;
            }
        }
        int maxValue=0;
        for(int i=0;i<matrix.size();i++){
            maxValue=max(maxValue,largestRectangleArea(prefixSum[i]));
        }
        return maxValue;
    }
};