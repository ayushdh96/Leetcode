class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int sizePushed=pushed.size();
    int sizePopped=popped.size();
    stack<int> st;
    int i=0,j=0;
    while(i<sizePushed && j<sizePopped){
        if(st.empty() || (pushed[i] != popped[j] && st.top() != popped[j])){
            st.push(pushed[i]);
            i++;
        }
        else if(popped[j]==pushed[i]){
            i++;
            j++;
        }
        else if(st.top()==popped[j]){
            st.pop();
            j++;
        }
    }
    
    
        while(!st.empty() && j< sizePopped && st.top()==popped[j]){
            st.pop();
            j++;
        }
    if(st.empty()) return true;
    else return false;

    }
    
};