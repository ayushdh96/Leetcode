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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        TreeNode *root=creatingTree(mpp,preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    
    return root;
    }
TreeNode* creatingTree(map<int,int>& mpp,vector<int>& preorder,vector<int>&inorder,int preOrderleft,int preOrderRight,int inOrderLeft,int inOrderRight){
    if(preOrderleft>preOrderRight||inOrderRight<inOrderLeft){
        return NULL;
    }

    TreeNode *root=new TreeNode(preorder[preOrderleft]);
    int center=mpp[preorder[preOrderleft]];
    int left=center-inOrderLeft;
    root->left=creatingTree(mpp,preorder,inorder,preOrderleft+1,preOrderleft+left,inOrderLeft,center-1);
    root->right=creatingTree(mpp,preorder,inorder,preOrderleft+left+1,preOrderRight,center+1,inOrderRight);
return root;
}
};