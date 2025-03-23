class Solution {
public:
    bool checkSymmetry(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr && subRoot==nullptr) return true;
        if (root==nullptr || subRoot==nullptr || root->val != subRoot->val) return false;
        return checkSymmetry(root->left, subRoot->left)
            && checkSymmetry(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr) return false;
        if (root->val==subRoot->val && checkSymmetry(root, subRoot)==true) return true;
        return isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot);
    }
};