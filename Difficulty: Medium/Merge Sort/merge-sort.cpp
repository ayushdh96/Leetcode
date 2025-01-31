//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r){return;}
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
    
    void merge(vector<int>& arr,int l,int r, int mid){
        vector<int> temp;
        int left=l, right=mid+1;
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        if(left<=mid){
            for(int i=left;i<=mid;i++){
                temp.push_back(arr[i]);
            }
        }
        if(right<=r){
            for(int i=right;i<=r;i++){
                temp.push_back(arr[i]);
            }
        }
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends