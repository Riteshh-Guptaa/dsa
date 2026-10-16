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
    int dfsDiameter(TreeNode* root, int &D){
        if(root == NULL) return 0;

        int lh = dfsDiameter(root->left, D);
        int rh = dfsDiameter(root->right, D);
        D = max(lh + rh, D);
        return max(lh, rh) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int D = 0;
        dfsDiameter(root, D);
        return D;
    }
};