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
    bool ansFinder(TreeNode* left, TreeNode* right){
        if(right == NULL && left == NULL) return true;
        if(right == NULL || left == NULL) return false;

        if(left->val != right->val ) return false;

        return ansFinder(left->left, right->right) && ansFinder(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return ansFinder(root->left, root->right);
    }
};