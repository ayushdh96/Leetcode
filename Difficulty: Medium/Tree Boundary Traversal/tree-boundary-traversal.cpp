/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
bool isLeaf(Node* root){
    if(root->left==NULL and root->right==NULL){
        return true;
    }
    else
    {
        return false;
    }
}
void addLeftBoundary(Node* root, vector<int>& ans){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr))
        {
            ans.push_back(curr->data);
        }
        if(curr->left!=NULL) curr=curr->left;
        else curr=curr->right;
    }
}
void addLeafNode(Node* root, vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left!=NULL){
        addLeafNode(root->left,ans);
    }
    if(root->right){
        addLeafNode(root->right,ans);
    }
}
void addRightNode(Node* root, vector<int>& ans){
    Node* curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
    
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeafNode(root, ans);
        addRightNode(root, ans);
        return ans;
    }
};