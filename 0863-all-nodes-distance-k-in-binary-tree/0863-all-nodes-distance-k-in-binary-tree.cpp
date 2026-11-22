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
    void MarkParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp){
        if(root == NULL) return;

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;

        MarkParents(root, parents);
        vector<int> ans;
        if(root == NULL || target == NULL) return ans;
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        queue<TreeNode*> q;
        q.push(target);

        while(!q.empty()){
          int n = q.size();
          if(k == 0) break;
          for(int i = 0; i < n; i++){
            
            auto node = q.front();
            q.pop();

            if(node->left && !visited.count(node->left)){
                visited.insert(node->left);
                q.push(node->left);
            }

            if(node->right && !visited.count(node->right)){
                visited.insert(node->right);
                q.push(node->right);
            }

            if(parents.count(node) && !visited.count(parents[node])){
                visited.insert(parents[node]);
                q.push(parents[node]);
            }
          }
          k--;
        }
       
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};