class Solution {
public:
    void reversal(vector<vector<int>> &ans, vector<int> &candidates, int target, vector<int> &curr, int idx){
        if(target == 0){
            ans.push_back(curr);
        }

        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            reversal(ans, candidates, target - candidates[i], curr, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, candidates, target, curr, 0);
        return ans;
    }
};