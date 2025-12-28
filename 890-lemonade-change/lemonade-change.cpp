class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mpp;
        mpp[5]=0,mpp[10]=0,mpp[20]=0;
        for(int i=0;i<bills.size();i++){
            int currentBill=bills[i]-5;
            while(currentBill!=0){
                int divison=currentBill/5;
                if(divison>1 && mpp[10]>0){
                    mpp[10]--;
                    currentBill-=10;
                }
                else if(mpp[5]>0){
                    mpp[5]--;
                    currentBill-=5;
                }
                else return false;
            }
            mpp[bills[i]]++;
        }
        return true;
    }
};