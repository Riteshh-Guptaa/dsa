class Solution {
public:
    void reversal(vector<vector<string>> &ans, vector<string> &board, int col, vector<int> &rowChecker, vector<int> &lowerDiog, vector<int> &upperDiog, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(rowChecker[row] == 0 && lowerDiog[row + col] == 0 && upperDiog[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                rowChecker[row]++;
                lowerDiog[row + col]++;
                upperDiog[n - 1 + col - row]++;
                reversal(ans, board, col + 1, rowChecker, lowerDiog, upperDiog, n);
                board[row][col] ='.';
                rowChecker[row] = 0;
                lowerDiog[row + col] = 0;
                upperDiog[n - 1 + col - row] = 0;
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

        vector<int> rowChecker(n, 0);
        vector<int> lowerDiog(2 * n - 1, 0);
        vector<int> upperDiog(2 * n - 1, 0);

        reversal(ans, board, 0, rowChecker, lowerDiog, upperDiog, n);
        return ans;
    }
};