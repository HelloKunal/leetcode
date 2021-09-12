class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int numCoins = coins.size();
        vector<vector<int>> dp (numCoins+1, vector<int>(amount+1));
        for(int x = 0; x <= amount; x++) dp[0][x] = 0;
        for(int y = 0; y <= numCoins; y++) dp[y][0] = 1;
        for(int y = 1; y <= numCoins; y++) {
            for(int x = 1; x <= amount; x++) {
                if(coins[y-1] <= x) {
                    dp[y][x] = dp[y-1][x] + dp[y][x - coins[y-1]];
                } else {
                    dp[y][x] = dp[y-1][x];
                }
            }
        }
        
        return dp[numCoins][amount];
    }
};