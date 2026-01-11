class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) st.push_back(asteroids[i]);
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                    st.pop_back();
                }
                if(st.empty()) st.push_back(asteroids[i]);
                else{
                    if(st.back()==abs(asteroids[i])) st.pop_back();
                    else if(st.back()<0) st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};