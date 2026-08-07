class Solution {
public:
    bool reversal(vector<vector<char>> &board, string word, int i, int j, int idx){
        if(idx == word.size()){
            return true;
        }
        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx]){
            return false;
        }
            char temp = board[i][j];
            board[i][j] = '#';

            bool found = reversal(board, word, i - 1, j, idx + 1) ||
                         reversal(board, word, i + 1, j, idx + 1) ||
                         reversal(board, word, i, j + 1, idx + 1) ||
                         reversal(board, word, i, j - 1, idx + 1);
            
            board[i][j] = temp;
            return found;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(reversal(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};