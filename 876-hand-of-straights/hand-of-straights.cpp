class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        if(hand.size()%groupSize!=0) return false;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]=mpp[hand[i]]+1;
        }
        auto it=mpp.begin();
        while(it!=mpp.end()){
            if(it->second==0) it++;
            else{
                int currValue=it->first;
                mpp[currValue]=mpp[currValue]-1;
                for(int i=1;i<groupSize;i++){
                if((mpp.find(currValue+i)!=mpp.end() && mpp[currValue+i]>=1)){
                    mpp[currValue+i]=mpp[currValue+i]-1;
                }
                else {
                    return false;
                }
                }
            }
        }
        return true;
    }
};