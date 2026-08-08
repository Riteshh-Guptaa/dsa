class Solution {
public:
    void reversal(vector<vector<string>> &ans, vector<string> &curr, vector<int> &rowChecker, vector<int> &lowerDiog, vector<int> &upperDiog, int col, int n){
        if(col == n){
            ans.push_back(curr);
            return;
        }

        for(int row = 0; row < n; row++){
            if(rowChecker[row] == 0 && lowerDiog[row + col] == 0 && upperDiog[n - 1 + col - row] == 0){
                curr[row][col] = 'Q';
                rowChecker[row]++;
                lowerDiog[row + col]++;
                upperDiog[n - 1 + col - row]++;
                reversal(ans, curr, rowChecker, lowerDiog, upperDiog, col + 1, n);
                curr[row][col] = '.';
                rowChecker[row]--;
                lowerDiog[row + col]--;
                upperDiog[n - 1 + col - row]--;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        vector<int> rowChecker(n, 0), leftDiog(2 * n - 1, 0), upperDiog(2 * n - 1, 0);
        reversal(ans, curr, rowChecker, leftDiog, upperDiog, 0, n);
        return ans;
    }
};