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
    bool isBalanced(TreeNode* root) {
        int ans=checkHeight(root);
        if(ans==-1){return false;}
        else{return true;}
    }
    int checkHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=checkHeight(root->left);
        if(left==-1){
            return -1;
        }
        int right=checkHeight(root->right);
        if(right==-1){
            return -1;
        }
        if(abs(left-right)>1){return -1;}
        else{
            return max(left,right)+1;
        }
    }
};