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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < preorder.size(); i++){
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(preorder, inorder, preIndex, mp, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int &preIndex, unordered_map<int, int>& mp, int left, int right){
        if(left > right) return NULL;
        int val = preorder[preIndex++];

        TreeNode* node = new TreeNode(val);
        int mid = mp[val];

        node->left = build(preorder, inorder, preIndex, mp, left, mid - 1);
        node->right = build(preorder, inorder, preIndex, mp, mid + 1, right);
        return node;
    }
};