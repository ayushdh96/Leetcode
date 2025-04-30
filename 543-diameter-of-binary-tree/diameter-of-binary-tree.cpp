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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        calculateMaximum(root,diameter);
        return diameter;
    }

    int calculateMaximum(TreeNode* root, int &diameter){
        if(root==NULL){
            return 0;
        }
        int left=calculateMaximum(root->left,diameter);
        int right=calculateMaximum(root->right,diameter);
        diameter=max(left+right,diameter);
        return 1+ max(left,right);

    }
};