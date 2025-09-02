// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int floor=-1;
        while(root){
            if(x==root->data) return root->data;
            else if(x>root->data){
                if(floor<root->data) floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }
};