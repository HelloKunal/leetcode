class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int xAxis = mat[0].size();
        int yAxis = mat.size();
        
        vector<vector<bool>> vis(yAxis, vector<bool>(xAxis, false));
        queue<pair<int, int>> q;
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                if(mat[y][x] == 0) {
                    q.push(make_pair(x, y));
                    vis[y][x] = true;
                }
            }
        }
        
        while(!q.empty()) {
            auto xy = q.front();            
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = xy.first + dx[i];
                int ny = xy.second + dy[i];
                
                if(nx < 0 || nx > xAxis-1 || ny < 0 || ny > yAxis-1 || vis[ny][nx]) continue;
                mat[ny][nx] = mat[xy.second][xy.first] + 1;
                q.push(make_pair(nx, ny));
                vis[ny][nx] = true;
            }
        }
        
        return mat;
    }
};