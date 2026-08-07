class Solution {
public:
     
    void reversal(vector<vector<string>> &ans, vector<string> &curr, int n, int col, vector<int> &rowChecker, vector<int> &upperDiog, vector<int> &lowerDiog){
        if(col == n){
            ans.push_back(curr);
            return;
        }

        for(int row = 0; row < n; row++){
            if(rowChecker[row] != 0 || upperDiog[n - 1 + col - row] != 0 
            || lowerDiog[col + row] != 0){
                continue;
            }
            curr[row][col] = 'Q';
            rowChecker[row]++;
            upperDiog[n - 1 + col - row]++;
            lowerDiog[col + row]++;
            reversal(ans, curr, n, col + 1, rowChecker, upperDiog, lowerDiog);
            curr[row][col] = '.';
            rowChecker[row]--;
            upperDiog[n - 1 + col - row]--;
            lowerDiog[col + row]--;
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        vector<int> rowChecker(n, 0),upperDiog(2 * n - 1, 0), lowerDiog(2 * n - 1, 0);
        reversal(ans, curr, n, 0, rowChecker, upperDiog, lowerDiog);
        return ans;
    }
};