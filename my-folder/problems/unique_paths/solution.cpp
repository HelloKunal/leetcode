class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m, 1);
        
        for(int j = 1; j < n; j++) {            
            int prev = 1;
            for(int i = 1; i < m; i++) { 
                dp[i] = dp[i] + prev;
                prev = dp[i];
            }
        }
        
        return dp[m-1];
    }
};