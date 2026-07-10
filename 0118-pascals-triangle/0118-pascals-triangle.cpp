class Solution {
public:
    vector<int> rowGenerator(int row){
        vector<int> res;
        res.push_back(1);
        if(row == 1){
            
            return res;
        }
        int val = 1;
        for(int i = 1; i < row; i++){
            val = val * (row - i);
            val = val/i;
            res.push_back(val);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(rowGenerator(i));
        }
        return ans;
    }
};