class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dpArr(n+1, vector<int> (amount+1));
        
        for(int i = 0; i <= amount; i++) dpArr[0][i] = INT_MAX - 1;
        for(int i = 0; i <= n; i++) dpArr[i][0] = 0;
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) dpArr[1][i] = i / coins[0];
            else dpArr[1][i] = INT_MAX - 1;
        }
        
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i-1] >= 0) {
                    dpArr[i][j] = min(dpArr[i-1][j], 1 + dpArr[i][j - coins[i-1]]);
                } else {
                    dpArr[i][j] = dpArr[i-1][j];
                }
            }
        }
        
        if(dpArr[n][amount] > amount) return -1;
        return dpArr[n][amount];
    }
};