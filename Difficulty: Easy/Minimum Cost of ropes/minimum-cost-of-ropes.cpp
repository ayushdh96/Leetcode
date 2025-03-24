//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        int sum=0,inserting=0;
        while(!q.empty()){
            inserting=0;
            int a=q.top();
            q.pop();
            inserting=a;
            if(!q.empty()){
                int b=q.top();
                q.pop();
                sum+=a+b;;
                inserting+=b;
                q.push(inserting);
            }
            else{
                break;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends