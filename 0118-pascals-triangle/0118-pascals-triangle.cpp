class Solution {
public:
    vector<int> generator(int row){
        vector<int> ans;
        int val = 1;
        ans.push_back(1);
        for(int i = 1; i < row; i++){
            val = val * (row - i);
            val = val/i;
            ans.push_back(val);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            ans.push_back(generator(i + 1));
        }
        return ans;
    }
};