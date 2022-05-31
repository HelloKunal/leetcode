class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int newColor, int oldColor) {
        grid[i][j] = newColor;
        
        for(int k = 0; k < 4; k++) {
            int di = i + dxy[k];
            int dj = j + dxy[k+1];
            
            if(di < 0 || dj < 0) continue;
            if(di >= grid.size() || dj >= grid[0].size()) continue;
            if(grid[di][dj] == oldColor) dfs(grid, di, dj, newColor, oldColor);
        }        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor != image[sr][sc]) dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};