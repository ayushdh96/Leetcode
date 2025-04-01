//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2){
            return kthElement(b,a,k);
        }
        int low=max(0,k-n2);
        int high=min(k,n1);
        int left=k;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(mid1<n1){r1=a[mid1];}
            if(mid2<n2){r2=b[mid2];}
            if(mid1-1>=0){l1=a[mid1-1];}
            if(mid2-1>=0){l2=b[mid2-1];}
            if(l1<=r2&&l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else if(l2>r1){
                low=mid1+1;
            }
        }
    return -1;}
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends