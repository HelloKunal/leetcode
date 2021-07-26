class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        if (len1 == 0)  return len2;
        if (len2 == 0)  return len1;
        
        int dp [len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= len2; i++)
        {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                int cost = (word1[i-1] == word2[j-1] ? 0 : 1);
                int temp = min (dp [i][j - 1] + 1, dp[i - 1][j] + 1);
                dp [i][j] = min (temp, dp[i - 1][j - 1] + cost);
            }
        }
        
        return dp[len1][len2];
    }
};