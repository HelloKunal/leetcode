class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp (d+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        int mod = pow(10, 9) + 7;
        for(int y = 1; y <= d; y++) {
            for(int x = 1; x <= target; x++) {
                for(int k = 1; k <= f; k++) {
                    if(k <= x) {
                        dp[y][x] = (dp[y][x]%mod + dp[y-1][x-k]%mod)%mod;
                    }
                }
            }
        }
        
        return dp[d][target];
    }
};