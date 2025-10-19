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
private:
    void traversal(TreeNode* parent,TreeNode* root, unordered_set<int>& st,vector<TreeNode*>& ans){
        if(root==NULL) return;
    
        traversal(root,root->left,st,ans);
        traversal(root,root->right,st,ans);
        
        if(st.find(root->val)!=st.end()){
            if(root->right!=NULL){
                ans.push_back(root->right);
                root->right=NULL;
            }
            if(root->left!=NULL){
                ans.push_back(root->left);
                root->left=NULL;
            }
        
            if(parent!=NULL){
                if(parent->left!=NULL && parent->left->val==root->val) parent->left=NULL;
                
                else parent->right=NULL;
        }
    }

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        traversal(NULL,root,st,ans);
        if(st.find(root->val)==st.end()) ans.push_back(root);
        return ans;
    }
};