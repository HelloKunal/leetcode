class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= n; i++) {
            dp[i] = 9;
            for(int j = 1, k = 9; j < i; j++, k--) {
                dp[i] *= k;
            }
            dp[i] += dp[i-1];
        }
        
        return dp[n];
    }
};