class Solution {
public:
    int min_Steps = INT_MAX;
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int bfs(vector<vector<int>> &grid) {
        int n = grid.size();
        int steps = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            steps++;
            
            int total = q.size();
            for(int i = 0; i < total; i++) {                
                auto xy = q.front();
                q.pop();
                if(grid[xy.first][xy.second] == 1) continue;
                if(xy.first == n-1 && xy.second == n-1) return steps;
                grid[xy.first][xy.second] = 1;
                for(int i = -1; i < 2; i++) {
                    for(int j = -1; j < 2; j++) {
                        if(xy.first+i > n-1 || xy.first+i < 0 || xy.second+j > n-1 || xy.second+j < 0) continue;
                        q.push(make_pair(xy.first+i, xy.second+j));
                    }
                }
            }            
        }
        return -1;        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = bfs(grid);
        return res;
    }
};