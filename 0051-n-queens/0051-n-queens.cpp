class Solution {
public:
    void reversal(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &lowerDiog, vector<int> &rowChecker, vector<int> &upperDiog, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(rowChecker[row] == 0 && upperDiog[n - 1 + col - row] == 0 && lowerDiog[row + col] == 0 ){
                board[row][col] = 'Q';
                rowChecker[row] = 1;
                upperDiog[n - 1 + col - row] = 1;
                lowerDiog[row + col] = 1;
                reversal(col + 1, board, ans, lowerDiog, rowChecker, upperDiog, n);
                board[row][col] = '.';
                rowChecker[row] = 0;
                upperDiog[n - 1 + col - row] = 0;
                lowerDiog[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s; 
        }
        vector<int> rowChecker(n, 0), upperDiog(2 * n - 1, 0), lowerDiog(2 * n - 1, 0);
        reversal(0, board, ans, lowerDiog, rowChecker, upperDiog, n);
        return ans;
    }
};