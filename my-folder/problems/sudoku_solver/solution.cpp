class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, char c) {
        for(int k = 0; k < 9; k++) {
            if(board[i][k] == c) return false;
            
            if(board[k][j] == c) return false;
            
            if(board[(i/3)*(3) + k/3][(j/3)*3 + k%3] == c) return false;
        }
        
        return true;
    }
    
    bool sSRec(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isSafe(board, i, j, c)) {
                            board[i][j] = c;
                            if(sSRec(board)) {
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
        sSRec(board);
    }
};