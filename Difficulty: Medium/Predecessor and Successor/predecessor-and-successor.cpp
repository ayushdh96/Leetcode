/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* minn=new Node(INT_MIN);
        Node* maxx=new Node(INT_MAX);
        ans.push_back(minn);
        ans.push_back(maxx);
        Node* curr=root;
        findPreAndSuc( root, key, ans);
        if(ans[0]->data==INT_MIN) ans[0]=NULL;
        if(ans[1]->data==INT_MAX) ans[1]=NULL;
        return ans;
    }
    void findPreAndSuc(Node* curr,int& key, vector<Node*>& ans){
        while(curr){
        if(curr->left==NULL){
        if(curr->data>ans[0]->data && curr->data<key) {ans[0]=curr;}
        else if(curr->data<ans[1]->data && curr->data>key) {ans[1]=curr;}
        curr=curr->right;}
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
                if(curr->data>ans[0]->data && curr->data<key) {ans[0]=curr;}
                else if(curr->data<ans[1]->data && curr->data>key) {ans[1]=curr;}
                curr=curr->right;
                temp->right=nullptr;
            }
        }
        }
    }
};