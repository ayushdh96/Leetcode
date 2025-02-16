//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int lower=-1,upper=arr.size(),first=0,last=arr.size()-1,mid=0;
        while(first<=last){
            mid=(first+last)/2;
            if(arr[mid]>=target){
                lower=mid;
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        first=0,last=arr.size()-1,mid=0;
        while(first<=last){
            mid=(first+last)/2;
            if(arr[mid]>target){
                upper=mid;
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        if(arr[lower]!=target){
            return 0;
        }
        else if(arr[upper-1]!=target){
            return 1;
        }
        else{
            return upper-lower;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends