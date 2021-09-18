class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int yMax = grid.size();
        int xMax = grid[0].size();
        int dp[yMax][xMax];
        for(int y = 0; y < yMax; y++) {
            for(int x = 0; x < xMax; x++) {
                if(y == 0 && x == 0) dp[y][x] = grid[y][x];
                else if(y == 0) dp[y][x] = grid[y][x] + dp[y][x-1];
                else if(x == 0) dp[y][x] = grid[y][x] + dp[y-1][x];
                else dp[y][x] = grid[y][x] + min(dp[y-1][x], dp[y][x-1]);
            }
        }
        
        return dp[yMax-1][xMax-1];
    }
};