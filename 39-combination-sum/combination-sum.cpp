class Solution {
public:
    void reversal(vector<vector<int>> &ans, vector<int> &curr, vector<int> &candidates, int target, int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            reversal(ans, curr, candidates, target - candidates[i], i);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, curr, candidates, target, 0);
        return ans;
    }
};