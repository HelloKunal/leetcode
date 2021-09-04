class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    
    int bfs (vector<vector<int>>& grid, int xAxis, int yAxis, queue<pair<int, int>> &q) {
        int res = 0;
        while(!q.empty()) {
            res++;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto xy = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = xy.first + dxy[i];
                    int ny = xy.second + dxy[i+1];
                    if(nx > xAxis-1 || nx < 0 || ny > yAxis-1 || ny < 0) continue;
                    if(grid[ny][nx] == 1){
                        grid[ny][nx] = 2;
                        q.push(make_pair(nx, ny));         
                    }           
                }
            }
        }
        return res-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int xAxis = grid[0].size();
        int yAxis = grid.size();
        int res = 0;
        queue<pair<int, int>> q;
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                if(grid[y][x] == 2) q.push(make_pair(x, y));
            }
        } 
        res = max(bfs(grid, xAxis, yAxis, q), 0);
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                if(grid[y][x] == 1) return -1;
            }
        }
        return res;
    }
};