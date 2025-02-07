//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int count=0;
        int l=0;
        int r=arr.size()-1;
        mergeSort(arr, l, r,count);
        return count;
    }
    void mergeSort(vector<int>& arr, int l, int r,int &count){
        if(l>=r){return;}
        int mid=(l+r)/2;
        mergeSort(arr,l,mid,count);
        mergeSort(arr,mid+1,r,count);
        merge(arr,l,r,mid,count);
    }
    
    void merge(vector<int>& arr,int l,int r, int mid,int &count){
        vector<int> temp;
        int left=l, right=mid+1;
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count=count+(mid-left+1);
                right++;
            }
        }
        if(left<=mid){
            for(int i=left;i<=mid;i++){
                temp.push_back(arr[i]);
            }
        }
        else if(right<=r){
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

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends