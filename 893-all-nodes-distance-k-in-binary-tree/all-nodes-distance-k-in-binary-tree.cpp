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
    unordered_map<TreeNode*, TreeNode*> parents;

    void markParents(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    parents[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;
        markParents(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode* > visited;
        visited.insert(target);
        q.push(target);
        int dist = 0;

        while(!q.empty()){
            int n = q.size();
            if(k == dist) break;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parents.count(node) && !visited.count(parents[node])){
                    q.push(parents[node]);
                    visited.insert(parents[node]);
                }
            }
            dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};