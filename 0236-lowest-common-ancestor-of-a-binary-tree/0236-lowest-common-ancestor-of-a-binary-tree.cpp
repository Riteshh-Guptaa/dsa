/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);


        if(left != NULL && right != NULL){
            return root;
        }else if(left == NULL && right != NULL){
            return right;
        }else if(right == NULL && left != NULL){
            return left;
        }else{
            return NULL;
        }


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = dfs(root, p, q);
        return node;
    }
};