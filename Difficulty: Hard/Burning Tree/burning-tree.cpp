/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void maxBurnTime(unordered_map<Node*,Node*>& mpp, Node* root , Node* targ, int& mbt){
        unordered_set<Node*> vis;
        queue<Node*> q;
        q.push(targ);
        vis.insert(targ);
        while(!q.empty()){
            int size=q.size();
            bool spread=false;
            for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left && vis.find(curr->left)==vis.end()){
                    vis.insert(curr->left);
                    q.push(curr->left);
                    spread=true;
                }
                if(curr->right && vis.find(curr->right)==vis.end()){
                    vis.insert(curr->right);
                    q.push(curr->right);
                    spread=true;
                }
                if(mpp[curr] && vis.find(mpp[curr])==vis.end()){
                    vis.insert(mpp[curr]);
                    q.push(mpp[curr]);
                    spread=true;
                }
            }
            if(spread==true) mbt=mbt+1;
        }
        
    }
    void calculateParent(unordered_map<Node*,Node*>& mpp, Node* root, int target, Node*& targ){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->data == target){
                targ=curr;
            }
            if(curr->left){
                q.push(curr->left);
                mpp[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                mpp[curr->right]=curr;
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>mpp;
        Node* targ;
        calculateParent(mpp,root,target, targ);
        int mbt=0;
        maxBurnTime(mpp,root,targ,mbt);
        return mbt;
    }
};