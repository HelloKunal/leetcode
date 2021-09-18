class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(y == 0 || x == 0) dp[y][x] = 1;
                else dp[y][x] = dp[y-1][x] + dp[y][x-1];
            }
        }
        return dp[m-1][n-1];
    }
};