class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int numCoins = coins.size();
        vector<vector<long long int>> dpArray(numCoins+1, vector<long long int> (amount+1));
        
        for(int i = 0; i <= amount; i++) dpArray[0][i] = INT_MAX-1;
        for(int y = 0; y <= numCoins; y++) dpArray[y][0] = 0;
        for(int x = 1; x <= amount; x++) {
            if(x % coins[0] == 0) dpArray[1][x] = x / coins[0];
            else dpArray[1][x] = INT_MAX-1;
        }
        
        for(int y = 2; y <= numCoins; y++) {
            for(int x = 1; x <= amount; x++) {
                
                if(x >= coins[y-1]) {
                    dpArray[y][x] = min(1 + dpArray[y][x-coins[y-1]], dpArray[y-1][x]);
                } else {
                    dpArray[y][x] = dpArray[y-1][x];
                }
            }
        }
        
        if(dpArray[numCoins][amount] > amount) return -1;
        else return dpArray[numCoins][amount];
    }
};