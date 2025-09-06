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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* newTemp=new TreeNode();
        newTemp=st.top();
        st.pop();
        int val=newTemp->val;
        if(newTemp->right){
            pushall(newTemp->right);
        }
        return val;

    }
    
    bool hasNext() {
        if(!st.empty()) {
            return true;}
        else {
            return false;
            }
    }
    void pushall(TreeNode*& root){
        st.push(root);
        root=root->left;
        while(root){
            st.push(root);
            root=root->left;
        }
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */