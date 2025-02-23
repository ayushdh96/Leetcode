//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int first=0,last=m,mid=0,ans=-1,multiply=1;
    while(first<=last){
        mid=(first+last)/2;
        multiply=1;
        for(int i=1;i<=n;i++){
            multiply=multiply*mid;
        }
        if(multiply==m){
            return mid;
        }
        else if(multiply<m){
            first=mid+1;
        }
        else{
            last=mid-1;
        }
    }
    return -1;    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends