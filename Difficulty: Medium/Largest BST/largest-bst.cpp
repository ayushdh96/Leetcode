/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxnode,minnode, maxsize;
    NodeValue(int maxnode,int minnode,int maxsize){
        this->maxnode=maxnode;
        this->minnode=minnode;
        this->maxsize=maxsize;
    }
};
class Solution {
  private:
  NodeValue bstCalculation(Node* root){
      if(!root) 
      return NodeValue(INT_MIN,INT_MAX,0);
      
      auto left=bstCalculation(root->left);
      auto right=bstCalculation(root->right);
      if(left.maxnode<root->data && right.minnode>root->data){
          return NodeValue(max(right.maxnode,root->data),min(left.minnode,root->data),left.maxsize+right.maxsize+1);
         
      }
      else{
          return NodeValue(INT_MAX,INT_MIN,max(left.maxsize,right.maxsize));
      }
      
  }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return bstCalculation(root).maxsize;
        
    }
};