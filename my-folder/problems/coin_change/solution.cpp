class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size_c = coins.size();
        vector<vector<long long int>> diffAmount_to_diffCoinArraySize(size_c+1, vector<long long int>(amount+1));
        
        for(int y = 0; y <= size_c; y++) {
            diffAmount_to_diffCoinArraySize[y][0] = 0;
        }
        for(int x = 1; x <= amount; x++) {
            diffAmount_to_diffCoinArraySize[0][x] = INT_MAX-1;
            // INTMAX - 1 because we check at code for min using arry[i][j] + 1, so no overflow.
        }
        for(int x = 1; x <= amount; x++) {
            if(x % coins[0] == 0) diffAmount_to_diffCoinArraySize[1][x] = x / coins[0];
            else diffAmount_to_diffCoinArraySize[1][x] = INT_MAX-1;
        }
        for(int y = 2; y <= size_c; y++) {
            for(int x = 1; x <= amount; x++) {
                if(coins[y-1] <= x) diffAmount_to_diffCoinArraySize[y][x] = min(diffAmount_to_diffCoinArraySize[y][x - coins[y-1]] + 1, diffAmount_to_diffCoinArraySize[y-1][x]);
                else diffAmount_to_diffCoinArraySize[y][x] = diffAmount_to_diffCoinArraySize[y-1][x];
            }
        }
        
        if(diffAmount_to_diffCoinArraySize[size_c][amount] > amount) return -1;
        else return diffAmount_to_diffCoinArraySize[size_c][amount];
    }
};