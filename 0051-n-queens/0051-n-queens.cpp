class Solution {
public:
    void reversal(vector<vector<string>> &ans, vector<string> &board, vector<int> &rowChecker, vector<int> &lowerDiog, vector<int> &upperDiog, int col, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(rowChecker[row] != 0 || lowerDiog[col + row] != 0 || upperDiog[n - 1 + col - row] != 0) continue;
            board[row][col] = 'Q';
            rowChecker[row]++;
            lowerDiog[col + row]++;
            upperDiog[n - 1 + col - row]++;
            reversal(ans, board, rowChecker, lowerDiog, upperDiog, col + 1, n);
            board[row][col] = '.';
            rowChecker[row]--;
            lowerDiog[col + row]--;
            upperDiog[n - 1 + col - row]--;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> rowChecker(n, 0), lowerDiog(2 * n - 1, 0), upperDiog(2 * n - 1, 0);
        reversal(ans, board, rowChecker, lowerDiog, upperDiog, 0, n);
        return ans;

    }
};