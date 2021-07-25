class Solution {
public:
    int superEggDrop(int eggs, int floors) {
                
        if (floors == 0)
            return 0;
        if (floors == 1)
            return 1;
        if (eggs == 1)
            return floors;
        
        int dp[eggs + 1][floors + 1];
        for (int i = 0; i <=eggs; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int i = 0; i <= floors; i++)
        {
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        
        for (int i = 2; i <=eggs; i++)
        {
            for (int j = 2; j <=floors; j++)
            {
                int ans = INT_MAX;
                int l = 1;
                int r = j;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];

                    if (left < right)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }

                    ans = min (ans, 1 + max (left, right));
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[eggs][floors];
    }
};