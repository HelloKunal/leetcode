class Solution {
public:
    int res = 0, count = 0;
    int dxy[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<int>> &grid, int x, int y) {
        grid[y][x] = 2;
        count++;
        
        for(int i = 0; i < 4; i++) {
            int dx = x + dxy[i];
            int dy = y + dxy[i+1];
            
            if(dx < 0 || dy < 0) continue;
            if(dy >= grid.size() || dx >= grid[0].size()) continue;
            if(grid[dy][dx] == 1) {
                dfs(grid, dx, dy);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int y = 0; y < grid.size(); y++) {
            for(int x = 0; x < grid[0].size(); x++) {
                if(grid[y][x] == 1) {
                    count = 0;
                    dfs(grid, x, y);
                    res = max(res, count);
                }
            }
        }
        
        return res;
    }
};