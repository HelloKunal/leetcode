class Solution {
public:
    void dfs(int x, int y, int xAxis, int yAxis, vector<vector<char>> &grid) {
        if(x < 0 || x > xAxis-1 || y < 0 || y > yAxis-1) return;
        if(grid[y][x] == '0' || grid[y][x] == '2') return;
        grid[y][x] = '2';
        
        dfs(x+1, y, xAxis, yAxis, grid);
        dfs(x-1, y, xAxis, yAxis, grid);
        dfs(x, y+1, xAxis, yAxis, grid);
        dfs(x, y-1, xAxis, yAxis, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int yAxis = grid.size();
        int xAxis = grid[0].size();
        
        int res = 0;
        for(int x = 0; x < xAxis; x++) {
            for(int y = 0; y < yAxis; y++) {
                if(grid[y][x] == '1') {
                    dfs(x, y, xAxis, yAxis, grid);
                    res++;
                }
            }
        }
        return res;
    }
};