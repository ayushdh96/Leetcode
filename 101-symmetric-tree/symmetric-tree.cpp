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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        int check=0;
        int truth=checkSymmetric(root->left,root->right, check);
        if(check==0){
            return true;
        }
        else{
            return false;
        }
    }
    int checkSymmetric(TreeNode* l, TreeNode* r, int &check){
        if(l==NULL && r==NULL){
            return 0;
        }
        else if((l==NULL && r!=NULL) || (l!=NULL && r==NULL)){
            check=-1;
            return -1;
        }
        if(l->val!=r->val){
            check=-1;
            return -1;
        }
        if(check==-1){
            return -1;
        }
        int left=checkSymmetric(l->left,r->right,check);
        int right=checkSymmetric(l->right,r->left,check);
        if(left==-1 || right==-1){
            check=-1;
            return -1;
        }
        return 0;
    }
};