class Solution {
public:
    void reversal(vector<vector<int>>& ans, vector<int>& curr, int start, int k, int idx){
        if(curr.size() == k){
            if(start == 0){
                ans.push_back(curr);
                return;
            }
        }

        for(int i = idx; i <= 9; i++){
            if(i > start) break;

            curr.push_back(i);
            reversal(ans, curr, start - i, k, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(ans, curr, n, k, 1);
        return ans;
    }
};