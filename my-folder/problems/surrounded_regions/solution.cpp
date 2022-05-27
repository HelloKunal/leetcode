class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<char>>& board, int y, int x) {
        board[y][x] = 'P';
        
        for(int i = 0; i < 4; i++) {
            int dy = y + dxy[i];
            int dx = x + dxy[i+1];
            
            if(dy >= board.size() || dy < 0 || dx >= board[0].size() || dx < 0) continue;
            if(board[dy][dx] == 'O') dfs(board, dy, dx);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int y = 0; y < m; y++) if(board[y][0] == 'O') dfs(board, y, 0);
        for(int y = 0; y < m; y++) if(board[y][n-1] == 'O') dfs(board, y, n-1);
        for(int x = 0; x < n; x++) if(board[0][x] == 'O') dfs(board, 0, x);
        for(int x = 0; x < n; x++) if(board[m-1][x] == 'O') dfs(board, m-1, x);
        
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(board[y][x] == 'O') board[y][x] = 'X';
                if(board[y][x] == 'P') board[y][x] = 'O';
            }
        }
    }
};