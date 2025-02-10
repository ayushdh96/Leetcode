class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftcalci=1,rightcalci=1;
        int maximum_value1=INT_MIN,maximum_value2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            leftcalci=leftcalci*nums[i];
            rightcalci=rightcalci*nums[nums.size()-1-i];
            maximum_value1=max(leftcalci,maximum_value1);
            maximum_value2=max(rightcalci,maximum_value2);
            if(nums[i]==0){leftcalci=1;}
            if(nums[nums.size()-1-i]==0){rightcalci=1;}
        }
        return max(maximum_value1,maximum_value2);
    }
};