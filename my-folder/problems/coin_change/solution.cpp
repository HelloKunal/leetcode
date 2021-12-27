class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dpArr(amount+1, vector<int> (n+1, 0));
        
        for(int i = 0; i <= amount; i++) dpArr[i][0] = INT_MAX-1;
        for(int i = 0; i <= n; i++) dpArr[0][i] = 0;
        for(int i = 1; i <= amount; i++) {
            if(i % coins[0] == 0) dpArr[i][1] = i / coins[0];
            else dpArr[i][1] = INT_MAX-1;
        }
        
        for(int i = 1; i <= amount; i++) {
            for(int j = 2; j <= n; j++) {
                if(coins[j-1] > i) dpArr[i][j] = dpArr[i][j-1];
                else {
                    int diff = i - coins[j-1];
                    dpArr[i][j] = min(dpArr[i][j-1], 1 + dpArr[diff][j]);
                }
            }
        }
        
        if(dpArr[amount][n] > amount) return -1;
        return dpArr[amount][n];
    }
};