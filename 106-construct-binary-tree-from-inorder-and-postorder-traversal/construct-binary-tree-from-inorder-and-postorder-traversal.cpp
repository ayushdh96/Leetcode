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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        if(inorder.empty()||postorder.empty()){ return NULL;}
        TreeNode* root=creatingTree(inorder,0, inorder.size()-1 ,postorder,0 , postorder.size()-1 , mpp);
        return root;
    }
    TreeNode* creatingTree(vector<int>& inorder,int instart, int inend ,vector<int>& postorder,int postart, int poend ,unordered_map<int, int>& mpp){
        if(poend<postart || instart>inend){
            return NULL;
        }
        int center=mpp[postorder[poend]];
        int left=center-instart;
        TreeNode* root=new TreeNode(postorder[poend]);
         root->left=creatingTree(inorder,instart, center-1 ,postorder,postart, postart+left-1 ,mpp);
         
         root->right=creatingTree(inorder,center+1, inend ,postorder,postart+left,poend-1 ,mpp);
         
        return root;
    }
};