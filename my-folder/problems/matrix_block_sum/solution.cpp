class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int yAxis = mat.size();
        int xAxis = mat[0].size();
        
        vector<vector<int>> dp(yAxis+1, vector<int> (xAxis+1, 0));
        for(int y = 1; y <= yAxis; y++) {
            for(int x = 1; x <= xAxis; x++) {
                dp[y][x] = dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1] + mat[y-1][x-1];
            }
        }
        
        vector<vector<int>> res(yAxis, vector<int> (xAxis));
        for(int y = 0; y < yAxis; y++) {
            for(int x = 0; x < xAxis; x++) {
                
                int top = max(0, y-k);
                int bottom = min(yAxis-1, y+k);
                int left = max(0, x-k);
                int right = min(xAxis-1, x+k);
                
                res[y][x] = dp[bottom+1][right+1] - dp[bottom+1][left] - dp[top][right+1] + dp[top][left];
            }
        }
        
        return res;
    }
};