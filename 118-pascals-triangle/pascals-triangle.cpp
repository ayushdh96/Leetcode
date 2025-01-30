class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        else if(numRows==2){
            return {{1},{1,1}};
        }
        else{
            vector<vector<int>> matrix;
            vector<int>temp;
            matrix.push_back({1});
            matrix.push_back({1,1});
            for(int i=2;i<numRows;i++){
                for(int j=0;j<=i;j++){
                    if(j==0 or j==(i)){
                        temp.push_back(1);
                    }
                    else{
                        temp.push_back(matrix[i-1][j-1]+matrix[i-1][j]);
                    }
                }
                matrix.push_back(temp);
                temp.clear();
            }
        return matrix;
        }
    }
};