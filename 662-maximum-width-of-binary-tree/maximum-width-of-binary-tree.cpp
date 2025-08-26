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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int max_width=0;
        calculateMaxWidth(root,max_width);
        return max_width;
    }
    void calculateMaxWidth(TreeNode* root,int& max_width){
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long minLevel=q.front().second;
            long long size=q.size();
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* currNode=q.front().first;
                long long currLevel=q.front().second-minLevel;
                q.pop();
                if(i==0) first=currLevel;
                if(i==size-1) last=currLevel;
                if(currNode->left){q.push({currNode->left,(currLevel*2)+1});}
                if(currNode->right){q.push({currNode->right,(currLevel*2)+2});}
            }
        max_width=max(max_width, last-first+1);
        }
    }
};