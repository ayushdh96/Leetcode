class MedianFinder {
public:
priority_queue<int> low;
priority_queue<int,vector<int>,greater<int>> high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        high.push(num);
        low.push(high.top());
        high.pop();
        if(low.size()>high.size()){
            high.push(low.top());
            low.pop();
        }        
    }
    double findMedian() {
        if(high.size()>low.size()){
            return high.top();
        }
        else
        {
            return (double)(low.top()+high.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */