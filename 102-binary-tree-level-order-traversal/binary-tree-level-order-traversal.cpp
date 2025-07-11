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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       queue<TreeNode* > q;
       if(root==NULL){
        return ans;
       }
       q.push(root);
       while(!q.empty()){
        vector<int> levels;
        int qSize=q.size();
        for(int i=1;i<=qSize;i++){
            TreeNode* tempNode=q.front();
            q.pop();
            if(tempNode->left!=NULL){
                q.push(tempNode->left);
            }
            if(tempNode->right!=NULL){
                q.push(tempNode->right);
            }
            levels.push_back(tempNode->val);
        }
        ans.push_back(levels);
       }
    return ans;
    }
};