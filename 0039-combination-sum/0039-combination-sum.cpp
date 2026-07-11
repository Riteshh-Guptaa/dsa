class Solution {
public:
    void solver(vector<int>& candidates, vector<vector<int>>& ans, vector<int> &curr, int target, int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(idx == candidates.size()){
            return;
        }

        if(target >= candidates[idx]){
            curr.push_back(candidates[idx]);
            solver(candidates, ans, curr, target - candidates[idx], idx);
            curr.pop_back();
        }
        solver(candidates, ans, curr, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solver(candidates, ans, curr, target, 0);
        return ans;
    }
};