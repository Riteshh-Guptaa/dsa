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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int leftCount = 0, rightCount = 0;
        TreeNode* leftHeight = root;
        TreeNode* rightHeight = root;

        while(leftHeight){
            leftHeight = leftHeight->left;
            leftCount++;
        }  

        while(rightHeight){
            rightHeight = rightHeight->right;
            rightCount++;
        }

        if(leftCount == rightCount){
            return (1 << leftCount) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};