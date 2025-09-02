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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            root=temp;
            return root;
        }
        TreeNode* curr=root;
        while(curr){
            if(curr->val>val){
                TreeNode* temp= curr->left;
                if(temp==NULL) {
                    TreeNode* newNode=new TreeNode(val);
                    curr->left=newNode;
                    return root;
                }
                else{
                    
                    
                        curr=curr->left;
                    
                }
            }
            else{
                TreeNode* temp= curr->right;
                if(temp==NULL) {
                    TreeNode* newNode=new TreeNode(val);
                    curr->right=newNode;
                    return root;
                }
                else{
                    
                    
                        curr=curr->right;
                    
                }
                
            }
        }
        return root;
    }
};