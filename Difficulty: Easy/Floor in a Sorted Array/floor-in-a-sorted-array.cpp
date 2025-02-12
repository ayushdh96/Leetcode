//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        int f=0,l=arr.size()-1,count=-1;
        bubbleSort(arr,k,f,l,count);
        return count;
    }
    
    void bubbleSort(vector<int>& arr,int k, int f, int l, int &count){
        
        if(f>l){return;}
        else{
            int mid=(f+l)/2;
            if(arr[mid]<=k){
                count=mid;
                f=mid+1;
            }
            else{
                l=mid-1;
            }
            bubbleSort(arr,k,f,l,count);
        }
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends