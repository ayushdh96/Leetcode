/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int isSumProperty(Node *root) {
        // code here
        if(root==NULL){
            return 1; 
        }
        int val=root->data;
        if(!root->left && !root->right){
            return 1;
        }
        else{
            int left=0,right=0;
            if(root->left)  left=root->left->data;
            if(root->right)  right=root->right->data;
            if(val!=left+right){
            return 0;
            }
        }
        
        int leftYes=isSumProperty(root->left);
        int rightYes=isSumProperty(root->right);
        if(leftYes==0||rightYes ==0){
            return 0;
        }
        return 1;
    }
};