class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    void dfs(int Axis, vector<vector<int>> &upscaledGrid, int i, int j) {
        upscaledGrid[i][j] = 2;
        for(int x = 0; x < 4; x++) {
            int ni = i + dxy[x];
            int nj = j + dxy[x+1];
            if(ni > Axis-1 || ni < 0 || nj > Axis-1 || nj < 0) continue;
            if(upscaledGrid[ni][nj] == 0) dfs(Axis, upscaledGrid, ni, nj);            
        }        
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int Axis = grid.size();
        int res = 0;
        vector<vector<int>> upscaledGrid(Axis*3, vector<int>(Axis*3, 0));
        
        for(int i = 0; i < Axis; i++) {
            for(int j = 0; j < Axis; j++) {
                if(grid[i][j] == '/') {
                    upscaledGrid[i*3][j*3 + 2] = upscaledGrid[i*3 + 1][j*3 + 1] = upscaledGrid[i*3 + 2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    upscaledGrid[i*3][j*3] = upscaledGrid[i*3 + 1][j*3 + 1] = upscaledGrid[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        
        for(int i = 0; i < Axis*3; i++) {
            for(int j = 0; j < Axis*3; j++) {
                if(upscaledGrid[i][j] == 0) {
                    dfs(Axis*3, upscaledGrid, i, j);
                    res++;
                }
            }
        }
        return res;        
    }
};