class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {       
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(obstacleGrid[y][x] == 1) continue;
                else if(y == 0 && x == 0) dp[0][0] = 1;
                else if(y == 0) dp[0][x] = dp[0][x-1];
                else if(x == 0) dp[y][0] = dp[y-1][0];
                else dp[y][x] = dp[y-1][x] + dp[y][x-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};