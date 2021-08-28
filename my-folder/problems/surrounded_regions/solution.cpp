class Solution {
public:
    void dfs(int i, int j, int xAxis, int yAxis, vector<vector<char>> &board) {
        if(i >= xAxis || i < 0 || j >= yAxis || j < 0) {
            return;
        }
        if(board[i][j] == 'O') {
            board[i][j] = '1';
            dfs(i+1, j, xAxis, yAxis, board);
            dfs(i, j+1, xAxis, yAxis, board);
            dfs(i-1, j, xAxis, yAxis, board);
            dfs(i, j-1, xAxis, yAxis, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int xAxis = board[0].size();
        if(xAxis <= 1) {
            return;
        }
        int yAxis = board.size();
        if(yAxis <= 1) {
            return;
        }
        
        for(int i = 0; i < yAxis; i++) {
            dfs(i, 0, yAxis, xAxis, board);
            dfs(i, xAxis-1, yAxis, xAxis, board);
        }
        for(int j = 0; j < xAxis; j++) {
            dfs(0, j, yAxis, xAxis, board);
            dfs(yAxis-1, j, yAxis, xAxis, board);
        }
        
        for(int i = 0; i < yAxis; i++) {
            for(int j = 0; j < xAxis; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};