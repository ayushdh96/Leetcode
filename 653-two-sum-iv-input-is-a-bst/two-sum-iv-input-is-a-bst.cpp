/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BstIterator{
    int reverse=1;
    stack<TreeNode*> st;
    public:
    BstIterator(TreeNode* root,int isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        int val=temp->val;
        if(reverse==1){
            if(temp->left) pushAll(temp->left);
        }
        else{
            if(temp->right) pushAll(temp->right);
        }
        return val;
    }
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse==1) root=root->right;
            else root=root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BstIterator r(root,1);
        BstIterator f(root,0);
        int i=f.next();
        int j=r.next();
        while(i<j){
            if((i+j)==k) return true;
            else if(i+j<k) i=f.next();
            else j=r.next();
        }
        return false;
    }
};