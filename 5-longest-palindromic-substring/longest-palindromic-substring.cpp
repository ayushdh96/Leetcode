class Solution {
public:
    string longestPalindrome(string s) {
            int left=0,right=0,left_max_value=0,right_max_value=0;
            int max_ans=0;
            for(int i=0;i<s.size();i++){
                left=i-1;
                right=i+1;
                int currAns=0;
                ;
                while(left>=0 && right<s.size()&&s[left]==s[right]){
                    currAns+=1;
                    left--;
                    right++;
                }
                currAns=(currAns*2) +1;
                if(max_ans<currAns){
                    max_ans=currAns;
                    left_max_value=left+1;
                    right_max_value=right-1;
                }

                left=i;
                right=i+1;
                currAns=0;
                ;
                while(left>=0 && right<s.size()&&s[left]==s[right]){
                    currAns+=1;
                    left--;
                    right++;
                }
                currAns*=2;
                if(max_ans<currAns){
                    max_ans=currAns;
                    left_max_value=left+1;
                    right_max_value=right-1;
                }

            }
            if(max_ans==1){
                return s.substr(0,1);
            }
            else return s.substr(left_max_value,right_max_value-left_max_value+1);
        
        return "Not Found";
    }
};