class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    void dfs(int y, int x, int yAxis, int xAxis, int originalColor, int newColor, vector<vector<int>> &image) {
        image[y][x] = newColor;
        for(int i = 0; i < 4; i++) {
            int ny = y + d[i+1];
            int nx = x + d[i];
            if(ny < 0 || ny > yAxis-1 || nx < 0 || nx > xAxis-1) continue;
            if(image[ny][nx] != originalColor) continue;
            dfs(ny, nx, yAxis, xAxis, originalColor, newColor, image);
       }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int xAxis = image[0].size();
        int yAxis = image.size();
        int originalColor = image[sr][sc];
        if(newColor != originalColor) dfs(sr, sc, yAxis, xAxis, originalColor, newColor, image);
        return image;
    }
};