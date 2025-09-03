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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr=root;
        int left=-1, right=-1;
        if(!root) return root;
        if(root->val==key){
            TreeNode* left= root->left;
            TreeNode* right= root->right;
            if(!right && left){
                TreeNode* prev=root;
                root=root->left;
                prev->left=NULL;
            }
            else if(!left && right){
                TreeNode* prev=root;
                root=root->right;
                prev->right=NULL;
            }
            else if(left &&  right){
                while(right->left){
                    right=right->left;;
                }
                right->left=left;
                root->left=nullptr;
                root=root->right;
                return root;
            }
            else{
                return NULL;
            }
        }
        else{
            TreeNode* curr=root;
            pair<TreeNode*,int> prev;
            while(curr){
                if(curr->val>key){
                    prev={curr,0};
                    curr=curr->left;
                }
                else if(curr->val<key){
                    prev={curr,1};
                    curr=curr->right;
                }
                else{
                    TreeNode* left= curr->left;
                    TreeNode* right= curr->right;
                    if(!right && left){
                        if(prev.second==0){
                            prev.first->left=left;
                        }
                        else{
                            prev.first->right=left;
                        }
                    }
                    else if(!left && right){
                        if(prev.second==0){
                            prev.first->left=right;
                        }
                        else{
                            prev.first->right=right;
                        }
                    }
                    else if (left && right){
                        if(prev.second==0){
                            prev.first->left=curr->left;
                            TreeNode* attach=curr->right;
                            curr=curr->left;
                            if(curr->right){
                            while(curr->right){
                                curr=curr->right;
                            }}
                            curr->right=attach;
                        }
                        else{
                            prev.first->right=curr->left;
                            TreeNode* attach=curr->right;
                            curr=curr->left;
                            if(curr->right){
                            while(curr->right){
                                curr=curr->right;
                            }}
                            curr->right=attach;
                        }
                    }
                    else{
                        if(prev.second==0){
                            prev.first->left=nullptr;
                        }
                        else prev.first->right=nullptr;
                    }
                return root;
                }
            }
        }
        return root;
    }
};