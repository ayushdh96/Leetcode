// User function Template for C++

class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int> ans;
        vector<int> list(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(list[i]==1){
                for(int j=i*i;j<=n;j=j+i){
                    list[j]=0;
                }
            }
        }
        return list;
    }
    int countPrimes(int L, int R) {
        // code here
        vector<int> seiveList=sieve(R);
        int sum=0;
        for(int i=2;i<=R;i++){
            sum=sum+seiveList[i];
            seiveList[i]=sum;
        }
        if(seiveList.size()>=1) seiveList[1]=0;
        seiveList[0]=0;
        return seiveList[R]-seiveList[L-1];
    }
};