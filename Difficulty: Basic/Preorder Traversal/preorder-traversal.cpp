/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        Node* curr=root;
        while(curr){
            if(curr->left==NULL){
                preorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    preorder.push_back(curr->data);
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    curr=curr->right;
                }
                
            }
        }
        return preorder;
    }
};