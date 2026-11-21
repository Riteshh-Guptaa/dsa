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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left, {row +1 , col - 1}});
            }

            if(node->right){
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        for(auto &col : mp){
            vector<int> level;
            for(auto &row : col.second){
                for(auto &val : row.second){
                    level.push_back(val);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};