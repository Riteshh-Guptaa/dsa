class Solution {
public:
    void reversal(vector<vector<int>> &ans, vector<int> &curr, vector<int> &candidates, int target, int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(idx == candidates.size()){
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            reversal(ans, curr, candidates, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, curr, candidates, target, 0);
        return ans;
    }
};