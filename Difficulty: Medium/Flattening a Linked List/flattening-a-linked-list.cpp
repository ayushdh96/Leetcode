/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* left, Node* right){
        Node* dummy= new Node(-1);
        Node* temp=dummy;
        temp->bottom=left;
        temp=left;
        left=left->bottom;
        while(right!=NULL && left!=NULL){
            if(left->data<right->data){
                temp->bottom=left;
                temp=left;
                left=left->bottom;
            }
            else{
                temp->bottom=right;
                temp=right;
                right=right->bottom;
            }
        }
        if(left!=NULL) temp->bottom=left;
        if(right!=NULL) temp->bottom=right;
        return dummy->bottom;
    } 
    Node *flatten(Node *root) {
        // code here
        if(root->next==NULL) return root;
        Node* temp=root;
        Node* nextNode=flatten(root->next);
        return merge(temp,nextNode);
    }
};