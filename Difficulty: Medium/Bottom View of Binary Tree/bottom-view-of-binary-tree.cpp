/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        vector<int> ans;
        map<int,int> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto qt=q.front();
            q.pop();
            mpp[qt.second]=qt.first->data;
            if(qt.first->left) q.push({qt.first->left,qt.second-1});
            if(qt.first->right) q.push({qt.first->right,qt.second+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};