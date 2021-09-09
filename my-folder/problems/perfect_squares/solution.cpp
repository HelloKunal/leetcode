class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            int min_temp = INT_MAX;
            
            for(int j = 1; j * j <= i; j++) {
                int res = i - j*j;
                if(dp[res] < min_temp) {
                    min_temp = dp[res];
                }
            }
            
            dp[i] = min_temp + 1;
        }
        
        return dp[n];
    }
};