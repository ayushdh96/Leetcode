/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void traversal(TreeNode* root, string& data){
        if(root==NULL){
            data.append("#,");
            return;
        }
        data.append(to_string(root->val)+",");
        traversal(root->left, data);
        traversal(root->right,data);


    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        traversal(root,data);
        return data;
    }
    TreeNode* build(stringstream& ss){
        string tok;
        getline(ss,tok,',');
        if(tok.empty()){return nullptr;}
        if(tok=="#"){return nullptr;}
        TreeNode* root=new TreeNode(stoi(tok));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        else{
            stringstream ss(data);
            return build(ss);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));