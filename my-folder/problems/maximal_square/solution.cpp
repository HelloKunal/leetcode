class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c));
        int res = 0;
        
        for(int row = r-1; row >= 0; row--) {
            for(int col = c-1; col >= 0; col--) {
                if(row == r-1 || col == c-1) {
                    dp[row][col] = matrix[row][col] - '0';               
                } else {
                    if(matrix[row][col] == '0') {
                        dp[row][col] = 0;
                    } else {
                        dp[row][col] = min(dp[row+1][col+1], min(dp[row+1][col], dp[row][col+1])) + 1;
                    }
                }
                
                if(dp[row][col] > res) {
                    res = dp[row][col];
                }
            }
        }        
        
        return res*res;
    }
};