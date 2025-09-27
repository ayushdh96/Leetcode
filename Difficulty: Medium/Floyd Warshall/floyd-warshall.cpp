// User function template for C++
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n=dist.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int leftLength=dist[j][i];
                    int rightLenght=dist[i][k];
                    if((leftLength!=1e8 && rightLenght!=1e8) && leftLength+rightLenght<dist[j][k]){
                        dist[j][k]=leftLength+rightLenght;
                    }
                }
            }
        }
        
    }
};