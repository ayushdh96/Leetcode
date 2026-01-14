class StockSpanner {
public:
    stack<pair<int,int>> st;
    int currentIndex=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
            currentIndex++;
            while(!st.empty() && st.top().second<=price){
                st.pop();
            }
            int ans=st.empty()?(currentIndex+1):(currentIndex-st.top().first);
            st.push({currentIndex,price});
            return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */