class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> DP(amount+1, vector<int> (n+1));
        
        for(int i = 0; i <= amount; i++) DP[i][0] = 0;
        for(int i = 0; i <= n; i++) DP[0][i] = 1;
        for(int i = 1; i <= amount; i++) {
            for(int j = 1; j <= n; j++) {
                if(coins[j-1] > i) DP[i][j] = DP[i][j-1];
                else {
                    DP[i][j] = DP[i][j-1] + DP[i - coins[j-1]][j];
                }
            }
        }
        
        return DP[amount][n];
    }
};