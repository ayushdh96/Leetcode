/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> inorder;
        Node* curr=root;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
                
            }
        }
        return inorder;
    }
};