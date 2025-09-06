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
    void recoverTree(TreeNode* root) {
        TreeNode* front=NULL;
        TreeNode* back=NULL;
        TreeNode* prev=NULL;
        traversalCapture(front, back, prev, root);
        if(front && back){
            int val=front->val;
            front->val=back->val;
            back->val=val;

        }
    }
    void traversalCapture(TreeNode*& front,TreeNode*& back, TreeNode*& prev, TreeNode* root){
        if(!root) return;
        traversalCapture(front,back, prev,root->left);
        if(prev && prev->val>root->val){
            back=root;
            if(front==NULL) front=prev;
        }
        prev=root;
        traversalCapture(front,back, prev,root->right);
    }
};