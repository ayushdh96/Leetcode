class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        if(n>=1) cout<<1<<" ";
        stack<int> st;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cout<<i<<" ";
                if(i*i!=n) st.push(n/i);
            }
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        if(n!=1) cout<<n;
    }
};