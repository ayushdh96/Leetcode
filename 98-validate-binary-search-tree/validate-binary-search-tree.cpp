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
    bool checkValidity(long long min, long long max, TreeNode* root){
        if(root==NULL) return true;
        if(root->val<=min || root->val>=max){
            return false;
        }
        return checkValidity(min,root->val,root->left) && checkValidity(root->val,max,root->right);
    }
    bool isValidBST(TreeNode* root) {
        long long min=LLONG_MIN;
        long long max=LLONG_MAX;
        bool check=checkValidity(min, max, root);
        return check;
    }
};