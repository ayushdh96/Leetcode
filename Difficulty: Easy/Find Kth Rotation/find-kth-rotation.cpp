//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        
        int first=0,last=arr.size()-1,mid=0, min_val=INT_MAX,index=0;
        while(first<=last){
            mid=(first+last)/2;
            if(arr[first]<=arr[mid]){
                if(min_val>=arr[first]){
                    index=first;
                    min_val=arr[first];
                }
                first=mid+1;
            }
            else{
                if(min_val>=arr[mid]){
                    min_val=arr[mid];
                    index=mid;
                }
                last=mid-1;
            }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends