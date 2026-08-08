class Solution {
public:
    bool isChecker(vector<vector<char>> &board, char val, int row, int col){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val){
                return false;
            }

            if(board[row][i] == val){
                return false;
            }

            if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == val){
                return false;
            }
        }
        return true;
    }

    bool reversal(vector<vector<char>> &board){
        for(int row = 0; row < 9; row ++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char i = '1'; i <= '9'; i++){
                        if(isChecker(board, i, row, col)){
                            board[row][col] = i;
                            if(reversal(board)){
                                return true;
                            }
                            board[row][col] = '.';
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