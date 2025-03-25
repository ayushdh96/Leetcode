class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> mapp(14,vector<int>(8,0));
        if(n==0){return cells;}
        for(int i=1;i<=6;i++){
            mapp[0][i]=(cells[i-1]==cells[i+1]);
        }
        for(int i=1;i<=13;i++){
            for(int j=1;j<=6;j++){
                mapp[i][j]=(mapp[i-1][j-1]==mapp[i-1][j+1]);
            }
        }
        return(mapp[(n-1)%14]);

    }
};