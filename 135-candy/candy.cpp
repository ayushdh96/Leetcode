class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i=1;
        while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){
                sum=sum+1;
                i++;
                continue;
            }
            int peak=1;
            while(i<ratings.size() && ratings[i-1]<ratings[i]){
                peak++;
                sum=sum+peak;
                i++;
            }
            int down=1;
            while(i<ratings.size() && ratings[i-1]>ratings[i]){
                sum=sum+down;
                down++;
                i++;
            }
            if(down>peak){
                sum=sum+(down-peak);
            }
        }
        return sum;
    }
};