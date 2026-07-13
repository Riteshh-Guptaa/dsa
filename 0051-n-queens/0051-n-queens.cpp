class Solution {

   
public:
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiog, vector<int>& lowerDiog, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiog[row + col] == 0 && upperDiog[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiog[row + col] = 1;
                upperDiog[n - 1 + col - row] = 1;
                solve(col + 1, ans, board, leftRow, upperDiog, lowerDiog, n);
                board[row][col] = '.';
                leftRow[row] = 0;
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

        vector<int> leftRow(n, 0), upperDiog(2 * n - 1, 0), lowerDiog(2 * n - 1, 0);

        solve(0, ans, board, leftRow, upperDiog, lowerDiog, n);
        return ans;
    }
};