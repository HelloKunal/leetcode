class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        for(int k = 0; k < 4; k++) {
            int nY = i + dxy[k];
            int nX = j + dxy[k+1];
            
            if(nX >= grid[0].size() || nY >= grid.size() || nX < 0 || nY < 0) continue;
            if(grid[nY][nX] == '1') dfs(grid, nY, nX);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int y = 0; y < grid.size(); y++) {
            for(int x = 0; x < grid[0].size(); x++) {
                if(grid[y][x] == '1') {
                    dfs(grid, y, x);
                    count++;
                }
            }
        }
        
        return count;
    }
};