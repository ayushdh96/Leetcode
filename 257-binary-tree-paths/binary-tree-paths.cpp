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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findAllPaths(root,"",ans);
        return ans;
    }
    void findAllPaths(TreeNode* node, string temp ,vector<string>& ans){
        if(node==NULL){
            return;
        }
        if(!temp.empty()){
            temp=temp+"->";
        }
        temp=temp+to_string(node->val);
        if(node->left)
        {
            findAllPaths(node->left,temp ,ans);
        }
        if(node->right){
            findAllPaths(node->right, temp ,ans);
        }
        if(!node->left && !node->right){
            ans.push_back(temp);
        }
    }
};