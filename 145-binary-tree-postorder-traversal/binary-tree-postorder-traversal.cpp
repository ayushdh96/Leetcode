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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

    postOrderTraversalNode(ans,root);
    return ans;
    }
    void postOrderTraversalNode(vector<int>& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        postOrderTraversalNode(ans,root->left);
        postOrderTraversalNode(ans,root->right);
        ans.push_back(root->val);
    }
};