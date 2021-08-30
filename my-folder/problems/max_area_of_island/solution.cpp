class Solution {
public:
    int maxArea;
    int d[5] = {0, 1, 0, -1, 0};
    void dfs(int &area, int x, int y, int xAxis, int yAxis, vector<vector<int>> &grid) {
        area++;
        maxArea = max(area, maxArea);
        grid[y][x] = 2;
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i+1];
            if(nx < 0 || nx > xAxis-1 || ny < 0 || ny > yAxis-1) continue;
            if(grid[ny][nx] == 2 || grid[ny][nx] == 0) continue;
            dfs(area, nx, ny, xAxis, yAxis, grid);            
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int xAxis = grid[0].size();
        int yAxis = grid.size();
        maxArea = 0;
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                if(grid[y][x] == 1) {                    
                    int area = 0;
                    dfs(area, x, y, xAxis, yAxis, grid);
                }
            }
        }
        
        return maxArea;
    }
};