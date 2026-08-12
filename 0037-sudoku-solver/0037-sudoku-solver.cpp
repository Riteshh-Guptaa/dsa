class Solution {
public:
    bool isCheck(vector<vector<char>> &board, char k, int row, int col){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == k){
                return false;
            }

            if(board[i][col] == k){
                return false;
            }

            if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == k){
                return false;
            }
        }
        return true;
    }
    bool reversal(vector<vector<char>> &board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                        if(isCheck(board, k, i, j)){
                            board[i][j] = k;
                            if(reversal(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        reversal(board);
        return;
    }
};