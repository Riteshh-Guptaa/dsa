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
    bool ansFinder(TreeNode* rootL, TreeNode* rootR){
        if(rootL == NULL && rootR == NULL) return true;
        if(rootL == NULL || rootR == NULL) return false;
        if(rootL->val != rootR->val) return false;

        return ansFinder(rootL->left, rootR->right) && ansFinder(rootL->right, rootR->left);

    }
    bool isSymmetric(TreeNode* root) {
        return ansFinder(root->left, root->right);
    }
};