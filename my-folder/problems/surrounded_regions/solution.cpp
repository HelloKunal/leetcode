class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[y][x] = '1';
        for(int i = 0; i < 4; i++) {
            int dx = x + dxy[i];
            int dy = y + dxy[i+1];
            if(dx < 0 || dx >= board[0].size() || dy < 0 || dy >= board.size()) continue;
            if(board[dy][dx] == 'O') dfs(board, dx, dy);            
        }        
    }
    
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') dfs(board, 0, i);
            if(board[i][board[0].size()-1] == 'O') dfs(board, board[0].size()-1, i);
        }
        for(int i = 0; i < board[0].size(); i++) {
            if(board[0][i] == 'O') dfs(board, i, 0);
            if(board[board.size()-1][i] == 'O') dfs(board, i, board.size()-1);
        }
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};