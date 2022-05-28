class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> qu;
        vector<vector<bool>> vis(mat.size(), vector<bool> (mat[0].size(), false));
        vector<vector<int>> res(mat.size(), vector<int> (mat[0].size(), 0));
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    qu.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        
        while(qu.size()) {
            auto curr = qu.front();
            qu.pop();
            int y = curr.first;
            int x = curr.second;
            
            for(int i = 0; i < 4; i++) {
                int dy = y + dxy[i];
                int dx = x + dxy[i+1];
                
                if(dy >= mat.size() || dy < 0 || dx >= mat[0].size() || dx < 0 || vis[dy][dx]) {
                    continue;
                }
                if(mat[dy][dx] == 0) continue;
                mat[dy][dx] = mat[y][x] + 1;
                qu.push({dy, dx});
                vis[dy][dx] = true;
            }
        }
        
        return mat;
    }
};