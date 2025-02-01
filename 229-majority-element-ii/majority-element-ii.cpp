class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int counter1=0, counter2=0, c1=0,c2=0;;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && counter2!=nums[i]){
                counter1=nums[i];
                c1=1;
            }
            else if(c2==0 && counter1!=nums[i]){
                counter2=nums[i];
                c2=1;
            }
            else if(counter1==nums[i]){
                c1++;
            }
            else if(counter2==nums[i]){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(int i=0;i<nums.size();i++){
            if(counter1==nums[i]){
                c1++;
            }
            else if(counter2==nums[i]){
                c2++;
            }}
        cout<<c1<<" "<<c2<<" "<<counter1<<" "<<counter2<<" "<<nums.size()/3;
        if(c1>nums.size()/3 && c2<=nums.size()/3){
            return {counter1};
        }
        else if(c1<=nums.size()/3 && c2>nums.size()/3){
            return {counter2};
        }
        else if(c1>nums.size()/3 && c2>nums.size()/3){
            return{counter1,counter2};
        }
        return{};
    }
};