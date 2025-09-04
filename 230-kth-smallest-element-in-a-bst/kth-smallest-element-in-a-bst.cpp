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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        TreeNode* curr= root;
        int ans;
        while(curr){
            if(curr->left==NULL){
                ++count;
                if(count==k){
                    ans=curr->val;
                }
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    ++count;
                    if(count==k){
                    ans=curr->val;
                    }
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};