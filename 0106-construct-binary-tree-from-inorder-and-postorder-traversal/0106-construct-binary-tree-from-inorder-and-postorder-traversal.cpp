/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return build(postorder, inorder, postIndex, mp, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int> &postorder, vector<int> &inorder, int &postIndex, unordered_map<int, int> &mp, int left, int right){
        if(left > right) return NULL;

        int val = postorder[postIndex--];

        TreeNode* node = new TreeNode(val);
        
        int mid = mp[val];

        node->right = build(postorder, inorder, postIndex, mp, mid + 1, right);
        node->left = build(postorder, inorder, postIndex, mp, left, mid - 1);
        return node;
    }
};