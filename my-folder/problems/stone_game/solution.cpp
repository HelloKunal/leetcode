class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n][n];
        
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, y = g; y < n; y++, i++)
            {
                if (g == 0)
                {
                    dp[i][y] = piles[i];
                }
                else if (g == 1)
                {
                    dp[i][y] = max (piles[i], piles[y]);
                }
                else
                {
                    int val1 = piles[i] + min (dp[i+1][y-1], dp[i+2][y]);
                    int val2 = piles[y] + min (dp[i+1][y-1], dp[i][y-2]);
                    
                    dp[i][y] = max (val1, val2);
                }
            }
        }
        return dp[0][n-1];
    }
};