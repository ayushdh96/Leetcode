class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        Node* curr=root;
        int ceil=-1;
        while(curr){
            if(x==curr->data) return curr->data;
            else if(x>curr->data) curr=curr->right;
            else{
                ceil=curr->data;
                curr=curr->left;
            }
        }
        return ceil;
    }
};
