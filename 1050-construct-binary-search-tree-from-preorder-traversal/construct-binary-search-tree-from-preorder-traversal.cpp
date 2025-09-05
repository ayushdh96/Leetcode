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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        
        int i=0;
        int bound=INT_MAX;
        return consturctTree(preorder, i, bound);
    }

    TreeNode* consturctTree( vector<int> preorder, int& i, int bound){
        if(i>=preorder.size() || preorder[i]>bound) return NULL;
        TreeNode* newNode=new TreeNode(preorder[i]);
        i=i+1;
        newNode->left=consturctTree( preorder, i, preorder[i-1]);
        newNode->right=consturctTree( preorder, i, bound);
        return newNode;
    }
};