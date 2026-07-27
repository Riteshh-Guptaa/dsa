class Solution {
public:
    void reversal(int k, int n, vector<vector<int>> &ans, vector<int> &curr, int idx){
        if(k == curr.size()){
            if(n == 0){
                ans.push_back(curr);
                
            }
            return;
        }

        for(int i = idx; i <= 9; i++){

            if(i > n) break;
            curr.push_back(i);
            reversal(k, n - i, ans, curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        reversal(k, n, ans, curr, 1);
        return ans;
    }
};