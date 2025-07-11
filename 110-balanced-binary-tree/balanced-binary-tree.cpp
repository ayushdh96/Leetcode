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
        int ans=checking(root);
        if(ans==-1){
            return false;
        }
        else{
            return true;
        }
    }

    int checking(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l=checking(root->left);
        if(l==-1){
            return -1;
        }
        int r=checking(root->right);
        if(r==-1)
        {
            return -1;
        }
        int sum=l-r;
        if(l-r<-1 || l-r>1){
            return -1;
        }
        else{
            return max(l,r)+1;
        }
    }
};