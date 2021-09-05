class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    void markDfs(vector<vector<int>> &grid, int y, int x, int color = 2) {
        grid[y][x] = color;
        int xAxis = grid[0].size();
        int yAxis = grid.size();
        for(int i = 0; i < 4; i++) {
            int nx = x + dxy[i];
            int ny = y + dxy[i+1];
            if(nx > xAxis-2 || nx < 1 || ny > yAxis-2 || ny < 1) continue;
            if(grid[ny][nx] == 0) markDfs(grid, ny, nx, color);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int xAxis = grid[0].size();
        int yAxis = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < xAxis; i++) {
            if(grid[0][i] == 0) markDfs(grid, 0, i);
            if(grid[yAxis-1][i] == 0) markDfs(grid, yAxis-1, i);
        }
        for(int i = 0; i < yAxis; i++) {
            if(grid[i][0] == 0) markDfs(grid, i, 0);
            if(grid[i][xAxis-1] == 0) markDfs(grid, i, xAxis-1);
        }
        
        int res = 0;
        for(int y = 1; y < yAxis-1; y++) {
            for(int x = 1; x < xAxis-1; x++) {
                if(grid[y][x] == 0) {
                    markDfs(grid, y, x, 3);
                    res++;
                }                
            }
        }
        return res;
    }
};