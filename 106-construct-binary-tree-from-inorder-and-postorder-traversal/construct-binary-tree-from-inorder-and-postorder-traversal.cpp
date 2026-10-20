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

        return build(inorder, postorder, mp, postIndex, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int &postIndex, int left, int right){
        if(left > right) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        root->right = build(inorder, postorder, mp, postIndex, mid + 1, right);
        root->left = build(inorder, postorder, mp, postIndex, left, mid - 1);
        return root;
    }
};