/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_visited(map<TreeNode*,TreeNode*>& mpp, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                mpp[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                mpp[curr->right]=curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mpp;
        parent_visited(mpp,root);
        int totDisTrav=0;
        unordered_set<int> vis;
        queue<TreeNode*>q;
        q.push(target);
        vis.insert(target->val);
        while(totDisTrav!=k){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && vis.find(curr->left->val)==vis.end()){
                    vis.insert(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right && vis.find(curr->right->val)==vis.end()){
                    vis.insert(curr->right->val);
                    q.push(curr->right);
                }
                if(mpp[curr] && vis.find(mpp[curr]->val)==vis.end()){
                    vis.insert(mpp[curr]->val);
                    q.push(mpp[curr]);
                }
            }
            totDisTrav++;
        }
        vector<int> ans;
        for(int i=0;i=q.size();i++){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};