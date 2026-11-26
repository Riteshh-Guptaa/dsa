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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "N,";
        }

        string s = to_string(root->val) + ',';
        s += serialize(root->left);
        s += serialize(root->right);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTrees(ss);
    }

    TreeNode* buildTrees(stringstream& ss){
        string val;
        getline(ss, val, ',');

        if(val == "N" || val == "NULL"){
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val));
        
        node->left = buildTrees(ss);
        node->right = buildTrees(ss);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));